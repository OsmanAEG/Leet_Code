// LeetCode: 199

#include <map>
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
  std::map<int, int> lvl_info;

  void depth_first_search(TreeNode* root, int depth) {
    if(root == nullptr) return;

    if(!lvl_info.count(depth)) {
      lvl_info[depth] = {root->val};
    }

    depth_first_search(root->right, depth + 1);
    depth_first_search(root->left,  depth + 1);
  }

  std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> lvl_vals;
    depth_first_search(root, 0);

    for(auto it = lvl_info.begin(); it != lvl_info.end(); ++it) {
      lvl_vals.push_back(it->second);
    }

    return lvl_vals;
  }
};