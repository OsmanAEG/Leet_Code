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
  int get_height(TreeNode* root, int& max_dia) {
    if(root == nullptr) return 0;

    const auto left  = get_height(root->left, max_dia);
    const auto right = get_height(root->right, max_dia);

    max_dia = std::max(left + right, max_dia);

    return 1 + std::max(left, right);
  }

  int diameterOfBinaryTree(TreeNode* root) {
    int max_dia = 0;
    const auto dummy = get_height(root, max_dia);
    return max_dia;
  }
};