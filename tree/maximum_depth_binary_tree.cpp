
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
 * 深度优先搜索（DFS）
 * time: O(n)
 * memory: O(h)
 */
class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        int max_level = 0;
        helper(root, 1, max_level);
        return max_level;
    }

private:
    void helper(TreeNode* root, int level, int &max_level)
    {
        if(!root)   return;
        if(level>max_level)
        {
            max_level = level;
        }
        if(root->left)
        {
            helper(root->left, level+1, max_level);
        }
        if(root->right)
        {
            helper(root->right, level+1, max_level);
        }
    }
};

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if(!root)   return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
