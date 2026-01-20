// LeetCode: 102

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
  std::map<int, std::vector<int>> level_order_map;

  void depth_first_search(TreeNode* root, int depth) {
    if(root == nullptr) return;

    level_order_map[depth].push_back(root->val);

    depth_first_search(root->left, depth + 1);
    depth_first_search(root->right, depth + 1);
  }

  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    depth_first_search(root, 0);

    std::vector<std::vector<int>> level_order_vec;

    for(auto it = level_order_map.begin(); it != level_order_map.end(); ++it) {
      level_order_vec.push_back(it->second);
    }

    return level_order_vec;
  }
};