//定义树的结构

#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int num;
    int getnode(TreeNode* root, int num) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left) {
            num++;
            getnode(root->left, num);
        }
        if (root->right) {
            num++;
            getnode(root->right, num);
        }

        return num;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return getnode(root, 1);
    }
};

int main() {
    Solution sol;
    TreeNode* t6 = new TreeNode(6);
    TreeNode* t5 = new TreeNode(5);
    
    TreeNode* root = new TreeNode(1);

    int sum = sol.countNodes(root);
    cout << sum << endl;
}