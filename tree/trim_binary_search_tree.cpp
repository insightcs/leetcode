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


/* 二叉树后序遍历 */
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (!root)
        {
            return nullptr;
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        if (root->val < L)
        {
            TreeNode* temp = root->right;
            //delete_tree(root->left);
            //delete root;
            return temp;
        }
        if (root->val > R)
        {
            TreeNode* temp = root->left;
            //delete_tree(root->right);
            //delete root;
            return temp;
        }
        return root;
    }

private:
    void delete_tree(TreeNode *root)
    {
        if(!root)   return;
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
};
