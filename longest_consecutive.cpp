/*
 * =====================================================================================
 *
 *       Filename:  longest_consecutive.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/24/2013 10:32:21 PM
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
#include <unordered_set>
#include <set>
#include <iostream>

using namespace std;

class Solution 
{
    public:
        int getCount(unordered_set<int>& numHash, int target, bool isAscend)
        {
            int count = 0;
            unordered_set<int>::iterator hashIter;
            while ((hashIter = numHash.find(target)) != numHash.end())
            {
                numHash.erase(hashIter);
                ++count;
                if (isAscend)
                    ++target;
                else
                    --target;
            }

            return count;
        }

        int longestConsecutive(vector<int> &num) 
        {
            int max = 0;
            int size = num.size();
            if (size == 0)
                return max;

            unordered_set<int> numHash;
            for (int i = 0; i != size; ++i)
                numHash.insert(num[i]);

            for (int i = 0; i != size; ++i)
            {
                int count = getCount(numHash, num[i], false) 
                            + getCount(numHash, num[i] + 1, true);

                if (count > max)
                    max = count;
            }

            return max;
        }
};

int main(int argc, char *argv[])
{
    int x[] = {0, 0, -1};
    vector<int> num(x, x + 3);

    Solution solution;
    int max = solution.longestConsecutive(num);

    cout << max << endl;

    return 0;
}
