/*
 * =====================================================================================
 *
 *       Filename:  pascal_triangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/13/13 14:45:10
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
    vector<int> getRow(int rowIndex) 
    {
        int size = rowIndex + 1;
        vector<int> prevRow(size, 1);
        vector<int> currRow(size, 1);

        for (int i = 2; i < size; ++i)
        {
            swap(prevRow, currRow);
            for (int j = 1; j != i; ++j)
                currRow[j] = prevRow[j-1] + prevRow[j];
        }

        return currRow;
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
    vector<int> row = solution.getRow(0);
    for (unsigned i = 0; i != row.size(); ++i)
        cout << row[i] << "\t";

    cout << endl;
    return 0;
}
