/*
 * =====================================================================================
 *
 *       Filename:  most_frequent_queries.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/22/2013 04:09:26 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include "header.hpp"

using namespace std;

class ComparePair
{
public:
    bool operator () (const pair<string, int>& a, const pair<string, int>& b)
    {
        if (a.second > b.second)
            return true;

        return false;
    }
};

class Solution
{
public:
    vector<pair<string, int>> mostFrequent(vector<string>& log, int k)
    {
        hash.clear();
        priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> minHeap;

        int size = log.size();
        for (int i = 0; i != size; ++i)
            ++hash[log[i]];

        int count = 0;
        unordered_map<string, int>::iterator iter;
        for (iter = hash.begin(); iter != hash.end(); ++iter)
        {
            ++count;
            if (count <= k)
                minHeap.push(*iter);
            else
            {
                const pair<string, int>& min = minHeap.top();
                if (min.second < iter->second)
                {
                    minHeap.pop();
                    minHeap.push(*iter);
                }
            }
        }

        vector<pair<string, int>> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }

private:
    unordered_map<string, int> hash;
};


int main(int argc, char *argv[])
{
    ifstream input;
    input.open(argv[1]);

    string temp;
    vector<string> log;
    while (input.good())
    {
        getline(input, temp);
        log.push_back(temp);
    }

    Solution solution;

    vector<pair<string, int>> result = solution.mostFrequent(log, 3);

    for (unsigned i = 0; i != result.size(); ++i)
        cout << result[i].first << "\t" << result[i].second << endl;

    return 0;
}
