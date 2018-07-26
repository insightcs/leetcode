#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left, *right;
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
    TreeNode* build_binary_tree(vector<int> &inorder, vector<int> &postorder)
    {
        if(inorder.size()==0)
        {
            return nullptr;
        }
        return helper(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }

private:
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int in_start,  int in_end, int post_start, int post_end)
    {
        int i = in_start;
        for(;i<=in_end;i++)
        {
            if (inorder[i] == postorder[post_end])
            {
                break;
            }
        }
        TreeNode *root = new TreeNode(inorder[i]);
        int left_len = i - in_start;
        int right_len = in_end - i;
        if(left_len>0)
        {
            root->left = helper(inorder, postorder, in_start, i-1, post_start, post_start+left_len-1);
        }
        if(right_len>0)
        {
            root->right = helper(inorder, postorder, i+1, in_end, post_start+left_len, post_end-1);
        }
        return root;
    }
};


int main(int argc, char* argv[])
{
    vector<int> inorder = {7, 4, 8, 2, 1, 5, 9, 3, 10, 6};
    vector<int> postorder = {7, 8, 4, 2, 9, 5, 10, 6, 3, 1};
    Solution s;
    TreeNode *root = s.build_binary_tree(inorder, postorder);
    return 0;
}