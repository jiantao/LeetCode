/*
 * =====================================================================================
 *
 *       Filename:  print_tree_with_indent.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2013 10:49:02 PM
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

struct Node
{
    int id;
    int pid;
    string label;
};

struct TreeNode
{
    string label;
    vector<TreeNode*> children;

    TreeNode (string x) : label(x) {};
};

class Solution
{
public:
    void printTreeWithIndent(const vector<Node>& array)
    {
        parentMap.clear();
        TreeNode* root = buildTree(array);
        printTree(root, "");
        destroyTree(root);
    }

private:
    TreeNode* buildTree(const vector<Node>& array)
    {
        TreeNode* root = NULL;
        for (unsigned i = 0; i != array.size(); ++i)
        {
            int pid = array[i].pid;
            int id = array[i].id;


            unordered_map<int, TreeNode*>::iterator iter;
            iter = parentMap.find(id);

            TreeNode* curr = NULL;
            if (iter == parentMap.end())
            {
                curr = new TreeNode(array[i].label);
                parentMap[id] = curr;
            }
            else
                curr = iter->second;

            if (pid == -1)
            {
                root = curr;
                continue;
            }

            iter = parentMap.find(pid);
            TreeNode* father = NULL;
            if (iter != parentMap.end())
                father = iter->second;
            else
            {
                father = new TreeNode(array[i].label);
                parentMap[pid] = father;
            }

            father->children.push_back(curr);
        }

        return root;
    }

    void printTree(const TreeNode* root, string indent)
    {
        if (root == NULL)
            return;

        cout << indent << root->label << endl;
        for (unsigned int i = 0; i != root->children.size(); ++i)
            printTree(root->children[i], indent + "\t");
    }

    void destroyTree(TreeNode* root)
    {
        if (root == NULL)
            return;

        for (unsigned i = 0; i != root->children.size(); ++i)
            destroyTree(root->children[i]);

        delete root;
    }

private:
    unordered_map<int, TreeNode*> parentMap;
};

int main(int argc, char *argv[])
{
    vector<Node> test(5);

    for (unsigned i = 0; i != 5; ++i)
    {
        test[i].id = i;
        test[i].label += 'A' + i;
    }

    test[0].pid = -1;
    test[1].pid = 0;
    test[2].pid = 1;
    test[3].pid = 1;
    test[4].pid = 0;

    Solution solution;

    solution.printTreeWithIndent(test);

    return 0;
}
