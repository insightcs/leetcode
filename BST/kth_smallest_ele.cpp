#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode* left, right;
    TreeNode(int x)
    {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }
}TreeNode;

/**
 * BST+中序遍历(recursively)
 * time: O(N)
 * space: O(N)
 * */
class Solution
{
public:
    int kthSamllest(TreeNode* root, int k)
    {
        if(!root)   return INT_MIN;
        vector<int> list;
        inorder_traversal(root, list);
        return list[k-1];
    }

private:
    void inorder_traversal(TreeNode* root, vector<int>& list)
    {
        if(!root)   return;
        inorder_traversal(root->left, list);
        list.push_back(root->val);
        inorder_traversal(root->right, list);
    }
};

/**
 * BST+中序遍历(iteratively)
 * time: O(k)
 * space: O(N)
 * */
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        if(!root)   return INT_MIN;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty()||cur)
        {
            if(!cur)
            {
                k--;
                TreeNode* node = s.top();
                s.pop();
                if(k==0)
                {
                    return node->val;
                }
                cur = node->right;
            }
            else
            {
                s.push(cur);
                cur = cur->left;
            }
        }
        return INT_MIN;
    }
};
