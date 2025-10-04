// LeetCode: 226

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
  void flip_nodes(TreeNode* root) {
    if(root == nullptr) return;

    auto left  = root->left;
    auto right = root->right;

    root->left  = right;
    root->right = left;

    if(left  != nullptr) flip_nodes(left);
    if(right != nullptr) flip_nodes(right);
  }

  TreeNode* invertTree(TreeNode* root) {
    flip_nodes(root);

    return root;
  }
};