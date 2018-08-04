#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
}TreeNode;


/**
 * DFS + set
 * time: O(N)
 * memory: O(N)
 * */
class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        set<int> s;
        return helper(root, k, s);
    }

private:
    bool helper(TreeNode* root, int k, set<int> &s)
    {
        if(!root)
        {
            return false;
        }
        if(s.find(k-root->val)!=s.end())
        {
            return true;
        }
        s.insert(root->val);
        return helper(root->left, k, s) || helper(root->right, k, s);
    }
};

/**
 * BFS + set
 * time: O(N)
 * memory: O(N)
 * */
class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        if(!root)   return false;
        set<int> s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(s.find(k-node->val)!=s.end())
            {
                return true;
            }
            s.insert(node->val);
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        return false;
    }
};

/**
 * BST
 * time: O(NH)
 * memory: O(H)
 */
class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        return dfs(root, root, k);
    }
private:
    bool dfs(TreeNode* root, TreeNode* node, int k)
    {
        if(!node)   return false;
        return search(root, node, k-node->val) || dfs(root, node->left, k) || dfs(root, node->right, k);
    }
    bool search(TreeNode* root, TreeNode* node, int value)
    {
        if (!root)
        {
            return false;
        }
        if(root!=node && root->val==value)
        {
            return true;
        }
        if(root->val>value)
        {
            return search(root->left, node, value);
        }
        if(root->val<value)
        {
            return search(root->right, node, value);
        }
        return false;
    }
};

/** BST
 * time: O(N)
 * memory: O(n)
 */
class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        vector<int> list;
        inorder_traversal(root, list);
        unsigned int start = 0;
        unsigned int end = list.size()-1;
        while(start<end)
        {
            if(list[start]+list[end]==k)
            {
                return true;
            }
            if(list[start]+list[end]<k)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
        return false;
    }

private:
    void inorder_traversal(TreeNode* root, vector<int> &list)
    {
        if(!root)   return;
        inorder_traversal(root->left, list);
        list.push_back(root->val);
        inorder_traversal(root->right, list);
    }
};