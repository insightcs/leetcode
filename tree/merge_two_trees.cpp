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

/* recursive: 二叉树前序遍历
 * time: O(m)
 * memory: O(m)*/
class Solution
{
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(!t1)
        {
            return t2;
        }
        if(!t2)
        {
            return t1;
        }
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

/* recursive: 二叉树层序遍历
 * time: O(n)
 * memory: O(n)*/
class Solution
{
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        if(!t1)
        {
            return t2;
        }
        if(!t2)
        {
            return t1;
        }
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;
        queue<TreeNode*> q1, q2;
        q1.push(t1);
        q2.push(t2);
        while(!q1.empty() && !q2.empty())
        {
            node1 = q1.front();
            node2 = q2.front();
            q1.pop();
            q2.pop();
            node1->val += node2->val;
            if(!node1->left)
            {
                node1->left = node2->left;
            }
            else if(node1->left && node2->left)
            {
                q1.push(node1->left);
                q2.push(node2->left);
            }
            if(!node1->right)
            {
                node1->right = node2->right;
            }
            else if(node1->right && node2->right)
            {
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }
        return t1;
    }
};
