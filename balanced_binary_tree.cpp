#include<algorithm>

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
  int get_height(TreeNode* root, bool& balanced) {
    if(root == nullptr) return 0;
    if(balanced == false) return 0;

    const auto left  = get_height(root->left, balanced);
    const auto right = get_height(root->right, balanced);

    if(std::abs(left - right) > 1) {
      balanced = false;
      return false;
    }

    return 1 + std::max(left, right);
  }

  bool isBalanced(TreeNode* root) {
    bool balanced = true;
    get_height(root, balanced);

    return balanced;
  }
};