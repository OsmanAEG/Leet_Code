#include<algorithm>
#include<climits>

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
  void validate_bst(TreeNode* root, long long min_val, long long max_val, bool& is_bst) {
    if(root != nullptr && is_bst == true) {
      auto left  = root->left;
      auto right = root->right;
      if(root->val <= min_val || root->val >= max_val) is_bst = false;
      validate_bst(left, min_val, root->val, is_bst);
      validate_bst(right, root->val, max_val, is_bst);
    }
  }

  bool isValidBST(TreeNode* root) {
    bool is_bst = true;
    validate_bst(root, LLONG_MIN, LLONG_MAX, is_bst);
    return is_bst;
  }
};