/*
 * =====================================================================================
 *
 *       Filename:  word_ladder2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/25/2013 02:11:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <string>
#include <deque>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution 
{
    struct Vertex
    {
        const string* pStr;
        int level;
        int id;

        Vertex(const string* otherStr, int otherLevel, int otherID)
            : pStr(otherStr), level(otherLevel), id(otherID)
        {

        }
    };

    struct Trace
    {
        const string* pStr;
        int jumpTo;

        Trace(const string* otherStr, int jump)
            : pStr(otherStr), jumpTo(jump)
        {

        }
    };

    void addNewVertex(unordered_set<string>& dict, unordered_set<string>& helpHash, deque<Vertex>& ladderQueue, vector<Trace>& traceBack)
    {
        const string& str = *(ladderQueue.front().pStr);
        int pLevel = ladderQueue.front().level;
        int pID = ladderQueue.front().id;

        int cLevel = pLevel + 1;
        int cID = traceBack.size() - 1;

        int strLen = str.length();
        string tempStr(str);
        unordered_set<string>::const_iterator dictIter;
        unordered_set<string>::const_iterator helpIter;
        for (int i = 0; i != strLen; ++i)
        {
            for (int j = 0; j != 26; ++j)
            {
                tempStr[i] = 'a' + j;
                if ((helpIter = helpHash.find(tempStr)) == helpHash.end()
                        && (dictIter = dict.find(tempStr)) != dict.end())
                {
                    ladderQueue.push_back(Vertex(&(*dictIter), cLevel, ++cID));
                    traceBack.push_back(Trace(&(*dictIter), pID));
                }
            }

            tempStr[i] = str[i];
        }
    }
    
    void PrepareResults(vector<vector<string>>& results, unordered_set<string>& keyHash, vector<Trace>& trackBack, deque<Vertex>& ladderQueue, int targetLevel, const string& end)
    {
        vector<string> tempResult;
        while (ladderQueue.size() > 0)
        {
            const string& str = *(ladderQueue.front().pStr);
            int level = ladderQueue.front().level;
            int id = ladderQueue.front().id;

            if (level != targetLevel)
                break;

            unordered_set<string>::const_iterator keyIter;
            if ((keyIter = keyHash.find(str)) != keyHash.end())
            {
                int size = level + 1;
                tempResult.resize(size);
                int index = id;
                for (int i = level; i >= 0; --i)
                {
                    tempResult[i] = *(trackBack[index].pStr);
                    index = trackBack[index].jumpTo;
                }

                tempResult.push_back(end);

                results.push_back(tempResult);
                tempResult.clear();
            }

            ladderQueue.pop_front();
        }
    }

public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
    {
        vector<vector<string>> results;
        unordered_set<string> helpHash;
        unordered_set<string> keyHash;
        vector<Trace> traceBack;
        vector<string> tempResult;
        deque<Vertex> ladderQueue;

        int strLen = start.length();

        unordered_set<string>::const_iterator dictIter;
        string tempStr(end);
        for (int i = 0; i != strLen; ++i)
        {
            for (int j = 0; j != 26; ++j)
            {
                tempStr[i] = 'a' + j;
                if ((dictIter = dict.find(tempStr)) != dict.end())
                {
                    keyHash.insert(*dictIter);
                }
            }

            tempStr[i] = end[i];
        }

        int level = 0;
        int id = 0;
        int jumpTo = -1;
        ladderQueue.push_back(Vertex(&start, level, id));
        helpHash.insert(start);
        traceBack.push_back(Trace(&start, jumpTo));

        int lastLevel = 0;
        while (ladderQueue.size() > 0)
        {
            const string& str = *(ladderQueue.front().pStr);
            int level = ladderQueue.front().level;
            if (level != lastLevel)
            {
                deque<Vertex>::const_iterator ladderIter;
                for (ladderIter = ladderQueue.begin(); ladderIter != ladderQueue.end(); ++ladderIter)
                    helpHash.insert(*(ladderIter->pStr));
            }

            lastLevel = level;

            unordered_set<string>::const_iterator keyIter;
            if ((keyIter = keyHash.find(str)) != keyHash.end())
            {
                PrepareResults(results, keyHash, traceBack, ladderQueue, level, end);
                break;
            }
            else
            {
                addNewVertex(dict, helpHash, ladderQueue, traceBack);
            }

            ladderQueue.pop_front();
        }

        return results;
    }
};


int main(int argc, char *argv[])
{
    string start("red");
    string end("tax");

    unordered_set<string> dict;
    dict.insert("ted");
    dict.insert("tex");
    dict.insert("red");
    dict.insert("tax");
    dict.insert("tad");
    dict.insert("den");
    dict.insert("rex");
    dict.insert("pee");

    Solution solution;
    vector<vector<string>> results = solution.findLadders(start, end, dict);

    for (unsigned int i = 0; i != results.size(); ++i)
    {
        for (unsigned int j = 0; j != results[i].size(); ++j)
            cout << results[i][j] << " ";

        cout << endl;
    }

    return 0;
}
