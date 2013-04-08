/*
 * =====================================================================================
 *
 *       Filename:  largest_rectangle_hist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/08/2013 03:24:16 PM
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
    int largestRectangleArea(vector<int> &height) 
    {
        stack.clear();
        int maxArea = 0;
        int size = height.size();

        for (int i = 0; i != size; ++i)
        {
            while (!stack.empty())
            {
                Node top = stack.back();
                if (height[i] >= top.val)
                {
                    stack.push_back(Node(height[i], i));
                    break;
                }
                else
                {
                    stack.pop_back();
                    int leftIdx = stack.empty() ? 0 : stack.back().idx + 1;
                    maxArea = max(maxArea, (i - leftIdx) * top.val);
                }
            }

            if (stack.empty())
                stack.push_back(Node(height[i], i));
        }

        int rightIdx = size;
        while (!stack.empty())
        {
            Node top = stack.back();
            stack.pop_back();
            int leftIdx = stack.empty() ? 0 : stack.back().idx + 1;
            maxArea = max(maxArea, (rightIdx - leftIdx) * top.val);
        }

        return maxArea;
    }

private:

    struct Node
    {
        int val;
        int idx;

        Node(int h, int i) : val(h), idx(i) {}
    };
    
    vector<Node> stack;
};


int main(int argc, char *argv[])
{
    vector<int> test(1, 0);

    Solution solution;
    int maxArea = solution.largestRectangleArea(test);

    cout << maxArea << endl;
    return 0;
}
