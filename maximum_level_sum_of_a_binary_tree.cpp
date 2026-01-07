// LeetCode: 1161

#include <algorithm>
#include <climits>
#include <unordered_map>

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
  std::unordered_map<int, int> sum;

  void search(TreeNode* root, int lvl) {
    sum[lvl] += root->val;

    if(root->left  != nullptr) search(root->left,  lvl + 1);
    if(root->right != nullptr) search(root->right, lvl + 1);
  }

  int maxLevelSum(TreeNode* root) {
    int max_val = INT_MIN;
    int max_lvl = 0;

    search(root, 1);

    for(auto it = sum.begin(); it != sum.end(); ++it) {
      if(it->second >= max_val) {
        max_val = it->second;
        max_lvl = it->first;
      }
    }

    return max_lvl;
  }
};