// LeetCode: 3315

#include <climits>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool valid = true;

  void validate_nodes(TreeNode* root, long min, long max) {
    if(valid == false) return;
    if(root == nullptr) return;

    const auto val = root->val;

    if(val <= min || val >= max) valid = false;

    validate_nodes(root->left,  min, val);
    validate_nodes(root->right, val, max);
  }

  bool isValidBST(TreeNode* root) {
    validate_nodes(root, LONG_MIN, LONG_MAX);
    return valid;
  }
};