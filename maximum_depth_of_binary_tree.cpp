// LeetCode: 104

#include <algorithm>

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
  int max_depth = 0;

  void find_max_depth(TreeNode* root, int height) {
    if(root == nullptr) {
      max_depth = std::max(max_depth, height);
      return;
    }

    find_max_depth(root->left,  height + 1);
    find_max_depth(root->right, height + 1);
  }

  int maxDepth(TreeNode* root) {
    find_max_depth(root, 0);
    return max_depth;
  }
};