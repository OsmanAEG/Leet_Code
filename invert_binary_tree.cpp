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
  void invert_nodes(TreeNode* root) {
    const auto node_left  = root->left;
    const auto node_right = root->right;

    root->left  = node_right;
    root->right = node_left;

    if(root->left  != nullptr) invert_nodes(root->left);
    if(root->right != nullptr) invert_nodes(root->right);
  }

  TreeNode* invertTree(TreeNode* root) {
    if(root != nullptr) invert_nodes(root);
    return root;
  }
};