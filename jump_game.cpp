/*
 * =====================================================================================
 *
 *       Filename:  jump_game.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2013 04:13:04 PM
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

class Solution {
public:
    bool canJump(int A[], int n) 
    {
        if (n < 2)
            return true;

        int target = n - 1;
        int i = n - 2;
        while (i >= 0)
        {
            if (i + A[i] >= target)
            {
                if (i == 0)
                    return true;
                else
                    target = i;
            }
            
            --i;
        }

        return false;
    }
};
