#include <algorithm>
#include <climits>

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
  void search(TreeNode* root, int& lvl, int& max_val, int& max_lvl, int& sum) {
    
  }

  int maxLevelSum(TreeNode* root) {
    int lvl = 0;
    int max_val = INT_MIN;
    int max_lvl = 0;
    int sum = 0;

    search(root, lvl, max_val, max_lvl, sum);
  }
};