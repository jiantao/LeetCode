/*
 * =====================================================================================
 *
 *       Filename:  jump_game2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/22/13 10:10:53
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
    int jump(int A[], int n) 
    {
        pos.clear();
        if (n <= 0)
            return -1;

        if (n == 1)
            return 0;

        int head = 1;
        pos.push_back(pair<int, int>(0, 0));
        while (pos.size() != 0)
        {
            int idx = pos.front().first;
            int step = pos.front().second;

            int end = idx + A[idx];
            if (end >= n - 1)
                return step + 1;

            for (int i = max(head, idx + 1); i <= end; ++i)
                pos.push_back(pair<int, int>(i, step + 1));

            pos.pop_front();
            head = end >= head ? end + 1 : head;
        }

        return -1;
    }

private:
    deque<pair<int, int>> pos;
};

int main(int argc, char *argv[])
{
    int test[] = {0, 2, 1, 1, 4};
    Solution solution;
    int step = solution.jump(test, 5);
    cout << step << endl;
    return 0;
}
