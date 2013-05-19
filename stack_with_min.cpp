/*
 * =====================================================================================
 *
 *       Filename:  stack_with_min.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/18/2013 12:27:03 AM
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

class StackWithMin
{
public:
    StackWithMin() {}
    ~StackWithMin() {}

    void pop(void)
    {
        if (data.size() == 0)
            return;

        if (data.back() == minData.back())
            minData.pop_back();

        data.pop_back();
    }

    void push(int num)
    {
        if (minData.size() == 0 || num <= minData.back())
            minData.push_back(num);

        data.push_back(num);
    }

    int top(void) const
    {
        if (data.size() == 0)
            return INT_MAX;

        return data.back();
    }

    int min(void) const
    {
        if (minData.size() == 0)
            return INT_MAX;

        return minData.back();
    }

private:
    vector<int> data;
    vector<int> minData;
};
