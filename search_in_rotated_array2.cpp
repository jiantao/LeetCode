/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/2013 10:16:32 PM
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
    bool search(int A[], int n, int target) 
    {
        for (int i = 0; i != n; ++i)
        {
            if (A[i] == target)
                return true;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
