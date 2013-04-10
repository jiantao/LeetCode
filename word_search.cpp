/*
 * =====================================================================================
 *
 *       Filename:  word_search.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/09/2013 11:40:44 PM
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

class Solution 
{
public:
    bool exist(vector<vector<char> > &board, string word) 
    {
        charSet.clear();
        posMap.clear();
        startPoints.clear();

        row = board.size();
        col = 0;
        if (row == 0)
            return false;
        else
        {
            col = board[0].size();
            if (col == 0)
                return false;
        }

        int strLen = word.length();
        if (strLen == 0)
            return true;

        if (!haveSameCharSet(board, word))
            return false;

        isFound = false;
        int numStarts = startPoints.size();
        for (int i = 0; i != numStarts; ++i)
        {
            posMap.clear();
            dfs(board, word, startPoints[i], 0);
            if (isFound)
                return true;
        }

        return false;
    }

private:
    void dfs(const vector<vector<char> >& board, const string& str, int pos, int len)
    {
        if (isFound)
            return;

        if (len == (int) str.length() - 1)
        {
            isFound = true;
            return;
        }

        int i = pos / col;
        int j = pos % col;

        unordered_set<int>::const_iterator iter;

        // left direction
        char nextChar = str[len + 1];
        if (j > 0 && board[i][j-1] == nextChar)
        {
            int newPos = pos - 1;
            iter = posMap.find(newPos);
            if (iter == posMap.end())
            {
                posMap.insert(newPos);
                dfs(board, str, newPos, len + 1);
            }
        }

        // right direction
        if (j < col-1 && board[i][j+1] == nextChar)
        {
            int newPos = pos + 1;
            iter = posMap.find(newPos);
            if (iter == posMap.end())
            {
                posMap.insert(newPos);
                dfs(board, str, newPos, len + 1);
            }
        }

        // up direction
        if (i > 0 && board[i-1][j] == nextChar)
        {
            int newPos = pos - col;
            iter = posMap.find(newPos);
            if (iter == posMap.end())
            {
                posMap.insert(newPos);
                dfs(board, str, newPos, len + 1);
            }
        }

        // down direction
        if (i < row-1 && board[i+1][j] == nextChar)
        {
            int newPos = pos + col;
            iter = posMap.find(newPos);
            if (iter == posMap.end())
            {
                posMap.insert(newPos);
                dfs(board, str, newPos, len + 1);
            }
        }

        // step back in the pos map
        posMap.erase(pos);
    }

    bool haveSameCharSet(const vector<vector<char> >& board, const string& word)
    {
        int row = board.size();
        int col = board[0].size();
        
        for (int i = 0; i != row; ++i)
        {
            for (int j = 0; j != col; ++j)
            {
                ++charSet[board[i][j]];
                if (board[i][j] == word[0])
                    startPoints.push_back(i * col + j);
            }
        }
        
        int strLen = word.length();
        for (int i = 0; i != strLen; ++i)
        {
            if (charSet[word[i]] == 0)
                return false;

            --charSet[word[i]];
        }

        return true;
    }

private:
    bool isFound;
    int row;
    int col;
    unordered_map<char, int> charSet;
    unordered_set<int> posMap;
    vector<int> startPoints;
};

int main(int argc, char *argv[])
{
    vector<vector<char> > board;
    vector<char> row;

    string temp = "b";
    for (unsigned i = 0; i != temp.size(); ++i)
        row.push_back(temp[i]);

    board.push_back(row);

    row.clear();
    temp = "a";
    for (unsigned i = 0; i != temp.size(); ++i)
        row.push_back(temp[i]);

    board.push_back(row);

    row.clear();
    temp = "b";
    for (unsigned i = 0; i != temp.size(); ++i)
        row.push_back(temp[i]);

    board.push_back(row);

    row.clear();
    temp = "b";
    for (unsigned i = 0; i != temp.size(); ++i)
        row.push_back(temp[i]);

    board.push_back(row);

    row.clear();
    temp = "a";
    for (unsigned i = 0; i != temp.size(); ++i)
        row.push_back(temp[i]);

    board.push_back(row);

    for (unsigned i = 0; i != board.size(); ++i)
    {
        for (unsigned j = 0; j != board[0].size(); ++j)
            printf("%c", board[i][j]);

        printf("\n");
    }

    string word("baa");

    Solution solution;
    bool isFound = solution.exist(board, word);
    if (isFound)
        printf("Found!\n");

    return 0;
}
