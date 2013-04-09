/*
 * =====================================================================================
 *
 *       Filename:  maximal_rectangle.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/07/2013 09:35:14 PM
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
    int maximalRectangle(vector<vector<char> > &matrix) 
    {
        int row = matrix.size();
        if (row == 0)
            return 0;

        int col = matrix[0].size();
        hist.resize(col, 0);

        int maxArea = 0;
        for (int i = 0; i != row; ++i)
        {
            for (int j = 0; j != col; ++j)
                hist[j] = matrix[i][j] == 0 ? 0 : hist[j] + 1;

            maxArea = max(maxArea, largestRectangleArea(hist));
        }

        return maxArea;
    }

private:

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

    vector<int> hist;
    vector<Node> stack;
};

int main(int argc, char *argv[])
{
    vector<char> test(2, 1);
    vector<vector<char> > matrix;

    Solution solution;
    int maxArea = solution.maximalRectangle(matrix);
    cout << maxArea << endl;

    test.assign(1, 0);
    maxArea = solution.maximalRectangle(matrix);
    cout << maxArea << endl;

    test.assign(2, 1);
    matrix.push_back(test);
    matrix.push_back(test);

    maxArea = solution.maximalRectangle(matrix);
    cout << maxArea << endl;
    return 0;
}
