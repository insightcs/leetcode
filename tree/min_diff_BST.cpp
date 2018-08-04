#include <iostream>
#include <cmath>
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

/* BST + 中序遍历
 * time: O(N)
 * memory: O(N)*/
class Solution
{
public:
    int minDiffInBST(TreeNode* root)
    {
        if (!root) return 0;
        vector<int> node_val;
        inorder_traversal(root, node_val);
        int min_diff = INT_MAX;
        for(int i=0;i<node_val.size()-1;i++)
        {
            int temp = abs(node_val[i+1] - node_val[i]);
            if(abs(temp < min_diff))
            {
                min_diff = temp;
            }
        }
        return min_diff;
    }

private:
    void inorder_traversal(TreeNode* root, vector<int>& node_val)
    {
        if(!root)   return;
        inorder_traversal(root->left, node_val);
        node_val.push_back(root->val);
        inorder_traversal(root->right, node_val);
    }
};

/* BST + DFS
 * time: O(N)
 * memory: O(N)*/
class Solution
{
public:
    int minDiffInBST(TreeNode* root)
    {
        if(!root)   return 0;
        int min_diff = INT_MAX;
        int pre = -1;
        dfs(root, min_diff, pre);
        return min_diff;
    }

private:
    void dfs(TreeNde* root, int& min_diff, int& pre)
    {
        if(!root)   return;
        dfs(root->left, min_diff, pre);
        if(pre!=-1)
        {
            min_diff = min(abs(root->val-pre), min_diff);
        }
        pre = root->val;
        dfs(root->right, min_diff, pre);
    }

};