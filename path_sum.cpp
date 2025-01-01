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
  bool path_summation(TreeNode* root, int running_sum, int targetSum) {
    if(root != nullptr) {
      running_sum += root->val;
      if(running_sum == targetSum && root->left == nullptr && root->right == nullptr) return true;
      return path_summation(root->left, running_sum, targetSum) || path_summation(root->right, running_sum, targetSum);
    } else {
      return false;
    }
  }

  bool hasPathSum(TreeNode* root, int targetSum) {
    return path_summation(root, 0, targetSum);
  }
};