#include <iostream>
#include <queue>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
}TreeNode;

class Solution
{
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res;
        helper(root, 1, res);
        return res;
    }

    void helper(TreeNode* root, unsigned int level, vector<double> &res)
    {
        if(!root)   return root;
        helper(root->left, level+1);
        helper(root->right, level+1);
        res[level] += root->val;
    }
};