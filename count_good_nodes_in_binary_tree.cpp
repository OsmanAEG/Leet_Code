// LeetCode: 1448

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
  int good_nodes = 0;

  void depth_first_search(TreeNode* root, int max_parent_val) {
    if(root == nullptr) return;

    if(root->val >= max_parent_val) {
      good_nodes += 1;
    }

    depth_first_search(root->left,  std::max(root->val, max_parent_val));
    depth_first_search(root->right, std::max(root->val, max_parent_val));
  }

  int goodNodes(TreeNode* root) {
    depth_first_search(root, root->val);

    return good_nodes;
  }
};