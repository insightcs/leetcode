#include <iostream>
#include <climits>
#include <map>
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

class Solution
{
public:
    int findBottomLeftValue(TreeNode* root)
    {
        if(!root)   return INT_MIN;
        map<int, int> table;
        int level = 0;
        helper(root, level, table);
        return table[level];
    }

private:
    void helper(TreeNode* root, int& level, map<int, int>& table)
    {
        if(table.count(level)==0)
        {
            table[level] = root->val;
        }
        helper(root->left, level+1, table);
        helper(root->right, level+1, table);
    }
};
