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
  void count_depth(TreeNode* root, int& max_count, int curr_count) {
    if(curr_count > max_count) max_count = curr_count;
    if(root->left  != nullptr) count_depth(root->left,  max_count, curr_count + 1);
    if(root->right != nullptr) count_depth(root->right, max_count, curr_count + 1);
  }

  int maxDepth(TreeNode* root) {
    int max_count = 0;
    if(root != nullptr) count_depth(root, max_count, 1);

    return max_count;
  }
};