/*
 * =====================================================================================
 *
 *       Filename:  food_tree_yelp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/18/2013 02:54:48 PM
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

struct TreeNode
{
    string food;
    vector<TreeNode*> subClasses;

    TreeNode (const char* name) : food(name) {}
    TreeNode (const string& name) : food(name) {}
};


class Solution
{
public:
    vector<string> getFoodNames(const TreeNode* root, const string& target)
    {
        result.clear();
        isFound = false;
        doGetFoodNames(root, target);

        return result;
    }

private:
    
    void doGetFoodNames(const TreeNode* root, const string& target)
    {
        if (root == NULL)
            return;

        if (!isFound && root->food == target)
            isFound = true;

        int size = root->subClasses.size();
        if (size == 0)
        {
            if (isFound)
                result.push_back(root->food);

            return;
        }

        for (int i = 0; i != size; ++i)
            doGetFoodNames(root->subClasses[i], target);
    }

private:
    bool isFound;
    vector<string> result;
};
