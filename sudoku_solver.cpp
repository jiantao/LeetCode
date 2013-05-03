/*
 * =====================================================================================
 *
 *       Filename:  sudoku_solver.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2013 11:52:13 PM
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
    void solveSudoku(vector<vector<char> > &board) 
    {
        empties.clear();
        isSolved = false;
        findEmpties(board);
        doSolveSudoku(board, 0);
    }

    void findEmpties(const vector<vector<char>>& board)
    {
        for (int i = 0; i != 9; ++i)
        {
            for (int j = 0; j != 9; ++j)
            {
                if (board[i][j] == '.')
                    empties.push_back(i * 9 + j);
            }
        }
    }

    void doSolveSudoku(vector<vector<char>>& board, int idx)
    {
        if (isSolved)
            return;

        if (idx >= (int) empties.size())
        {
            isSolved = true;
            return;
        }

        int r = empties[idx] / 9;
        int c = empties[idx] % 9;
        for (int i = 1; i <= 9; ++i)
        {
            if (canPlace(board, r, c, i))
            {
                board[r][c] = '0' + i;
                doSolveSudoku(board, idx + 1);
                if (isSolved)
                    return;

                board[r][c] = '.';
            }
        }
    }
     
private:
     
    bool canPlace(vector<vector<char> > &board, int i, int j, int f)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[i][k] - '0' == f)
                return false;
        }
         
        for (int k = 0; k < 9; k++)
        {
            if (board[k][j] - '0' == f)
            return false;
        }
         
        int x = i / 3 * 3;
        int y = j / 3 * 3;
        for (int a = x; a < x + 3; a++)
        {
            for (int b = y; b < y + 3; b++)
            {
                if (board[a][b] - '0' == f)
                    return false;
            }
        }
         
        return true;
    }

private:
    vector<int> empties;
    bool isSolved;
};


int main(int argc, char *argv[])
{
    char row[9][10] = {"..9748...", "7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
    vector<vector<char>> board;
    board.resize(9);
    for (int i = 0; i != 9; ++i)
        board[i].resize(9);

    for (int i = 0; i != 9; ++i)
    {
        for (int j = 0 ;j != 9; ++j)
        {
            board[i][j] = row[i][j];
            cout << board[i][j];
        }
        cout << endl;
    }

    cout << endl;
    Solution solution;
    solution.solveSudoku(board);
    for (int i = 0; i != 9; ++i)
    {
        for (int j = 0 ;j != 9; ++j)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
