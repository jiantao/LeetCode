/*
 * =====================================================================================
 *
 *       Filename:  n_queens2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2013 12:28:37 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jiantao Wu (), 
 *        Company:  
 *
 * =====================================================================================
 */


class Solution 
{
public:
    int totalNQueens(int n) 
    {
        if (n == 1)
            return 1;

        if (n < 4)
            return 0;

        sum = 0;
        upperLimit = (1 << n) - 1;

        compute(0, 0, 0);
        return sum;
    }

private:
    void compute(long row, long ld, long rd)
    {
        if (row != upperLimit)
        {
            // get all the available place to place a queen
            // 1 means available; 0 means not available
            // ld is the left diagnol, rd is the right diagnol
            long pos = upperLimit & ~(row | ld | rd);

            while (pos != 0)
            {
                // get the rightmost "1" (the positino is available for a queen)
                long p = pos & -pos;
                // remove the positionfor next iterator
                pos -= p;

                // set the position on the row
                compute(row + p, (ld + p) << 1, (rd + p) >> 1);
            }
        }
        else
        {
            // a solution is found
            // update the counter
            ++sum;
        }
    }

private:
    int sum;
    long upperLimit;

};
