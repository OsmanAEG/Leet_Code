// LeetCode: 230

#include <vector>

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
  std::vector<int> vals;
  void depth_first_search(TreeNode* root) {
    if(root == nullptr) return;

    depth_first_search(root->left);
    vals.push_back(root->val);
    depth_first_search(root->right);
  }

  int kthSmallest(TreeNode* root, int k) {
    depth_first_search(root);
    return vals[k-1];
  }
};