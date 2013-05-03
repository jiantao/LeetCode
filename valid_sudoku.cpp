/*
 * =====================================================================================
 *
 *       Filename:  valid_sudoku.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 10:40:54 PM
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
    bool isValidSudoku(vector<vector<char> > &board) 
    {
        int n = board.size();
        for (int i = 0; i != n; ++i)
        {
            check.assign(9, false);
            for (int j = 0; j != n; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                if (check[num - 1])
                    return false;
                else
                    check[num - 1] = true;
            }
        }

        for (int i = 0; i != n; ++i)
        {
            check.assign(9, false);
            for (int j = 0; j != n; ++j)
            {
                if (board[j][i] == '.')
                    continue;

                int num = board[j][i] - '0';
                if (check[num - 1])
                    return false;
                else
                    check[num - 1] = true;
            }
        }

        for (int c = 0; c != 9; ++c)
        {
            check.assign(9, false);
            for (int i = c / 3 * 3; i != c / 3 * 3 + 3; ++i)
            {
                for (int j = c % 3 * 3; j != c % 3 * 3 + 3; ++j)
                {
                    if (board[i][j] == '.')
                        continue;

                    int num = board[i][j] - '0';
                    if (check[num - 1])
                        return false;
                    else
                        check[num - 1] = true;
                }
            }
        }

        return true;
    }

private:
    vector<bool> check;
};
