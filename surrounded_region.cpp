/*
 * =====================================================================================
 *
 *       Filename:  surrounded_region.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2013 02:38:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;


class Solution
{
    struct Pos
    {
        int i;
        int j;

        Pos(int a, int b)
        {
            i = a;
            j = b;
        }
    };

    void solve(vector<vector<char> > &board) 
    {
        int row = board.size();
        if (row == 0)
            return;

        int col = board[0].size();
        if (col == 0)
            return;

        deque<Pos> posQueue;

        for (int i = 0; i != row; ++i)
        {
            for (int j = 0; j != col; ++j)
            {
                if (board[i][j] == 'O' && (i == 0 || j == 0 || i == row - 1 || j == col - 1))
                    posQueue.push_back(Pos(i, j));
            }
        }

        while (posQueue.size() > 0)
        {
            const Pos& currPos = posQueue.front();
            int i = currPos.i;
            int j = currPos.j;
            if (board[i][j] == 'O')
            {
                board[i][j] = 'Z';
                if (i > 0 && board[i-1][j] == 'O')
                    posQueue.push_back(Pos(i-1, j));

                if (j > 0 && board[i][j-1] == 'O')
                    posQueue.push_back(Pos(i, j-1));

                if (i < row-1 && board[i+1][j] == 'O')
                    posQueue.push_back(Pos(i+1, j));

                if (j < col-1 && board[i][j+1] == 'O')
                    posQueue.push_back(Pos(i, j+1));
            }

            posQueue.pop_front();
        }

        for (int i = 0; i != row; ++i)
        {
            for (int j = 0; j != col; ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'Z')
                    board[i][j] = 'O';
            }
        }
    }
};
