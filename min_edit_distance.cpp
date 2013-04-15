/*
 * =====================================================================================
 *
 *       Filename:  min_edit_distance.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/2013 10:56:10 PM
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
    int minDistance(string word1, string word2) 
    {
        int row = word1.length();
        int col = word2.length();

        if (row == 0)
            return col;

        if (col == 0)
            return row;

        preprocess(row, col);

        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                int diagnol = word1[i-1] == word2[j-1] ? scoreMatrix[i-1][j-1] : scoreMatrix[i-1][j-1] + 1;
                int min = diagnol;
                if (min > scoreMatrix[i][j-1] + 1)
                    min = scoreMatrix[i][j-1] + 1;

                if (min > scoreMatrix[i-1][j] + 1)
                    min = scoreMatrix[i-1][j] + 1;

                scoreMatrix[i][j] = min;
            }
        }

        return scoreMatrix[row][col];
    }

private:

    void preprocess(int row, int col)
    {
        scoreMatrix.resize(row + 1);
        for (int i = 0; i <= row; ++i)
            scoreMatrix[i].resize(col + 1, 0);

        for (int i = 0; i <= col; ++i)
            scoreMatrix[0][i] = i;

        for (int i = 0; i <= row; ++i)
            scoreMatrix[i][0] = i;
    }

private:
    vector<vector<int> > scoreMatrix;
};
