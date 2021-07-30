#include "leetcode.h"
using namespace std;

// 二叉树的遍历
void transverse(TreeNode *root, vector<int> &ret) {
    if (!root)
        return;
    ret.push_back(root->val);

    transverse(root->left, ret);
    transverse(root->right, ret);
}

vector<int> preorder(TreeNode *root) {
    vector<int> ret;
    transverse(root, ret);
    return ret;    
}