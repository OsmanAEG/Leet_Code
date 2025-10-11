// LeetCode: 110

#include <algorithm>

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
  bool balanced = true;

  int check_height(TreeNode* root) {
    if(root == nullptr) return 0;
    if(balanced == false) return 0;

    auto left_height  = check_height(root->left);
    auto right_height = check_height(root->right);

    if(std::abs(left_height - right_height) > 1) {
      balanced = false;
      return false;
    }

    return 1 + std::max(left_height, right_height);
  }

  bool isBalanced(TreeNode* root) {
    check_height(root);

    return balanced;
  }
};