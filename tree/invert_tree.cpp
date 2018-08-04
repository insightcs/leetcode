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

/**
 * recursive
 * time: O(N)
 * memory: O(H)
 */
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root)   return root;
        TreeNode* temp = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(temp);
        return root;
    }
};

/**
 * iterative
 * time: O(N)
 * memory: O(N)
 */
class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if(!root)   return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
            TreeNode* temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        return root;
    }
};

int main(int argc, char* argv[])
{
    TreeNode *root = new TreeNode(4);
    TreeNode *p = root;
    p->left = new TreeNode(2);
    p->right = new TreeNode(7);
    p->left->left = new TreeNode(1);
    p->left->right = new TreeNode(3);
    p->right->left = new TreeNode(6);
    p->right->right = new TreeNode(9);

    Solution *s = new Solution;
    root = s->invertTree(root);
    delete s;
    return 0;
}