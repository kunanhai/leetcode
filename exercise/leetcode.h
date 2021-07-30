#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL);
}