#include <iostream>
#include <vector>
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

/* 深度优先搜索 */
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res;
        vector<double> level_nodes;
        helper(root, 0, level_nodes, res);
        for(unsigned int i=0;i<res.size();i++)
        {
            res[i] /= level_nodes[i];
        }
        return res;
    }

    void helper(TreeNode* root, unsigned int level, vector<double> &level_nodes, vector<double> &res)
    {
        if(!root)   return;
        if(level<res.size())
        {
            res[level] += (double)root->val;
            level_nodes[level] += 1.0;
        }
        else
        {
            res.push_back((double)root->val);
            level_nodes.push_back(1.0);
        }
        helper(root->left, level+1, level_nodes, res);
        helper(root->right, level+1, level_nodes, res);
    }
};

int main(int argc, char* argv[])
{
    TreeNode* root = new TreeNode(3);
    TreeNode* p = root;
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p = p->right;
    p->left = new TreeNode(15);
    p->right = new TreeNode(7);

    Solution *s;
    vector<double> res = s->averageOfLevels(root);
    for(auto it:res)    cout << it << endl;
    delete s;
    return 0;
}