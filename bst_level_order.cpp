#include<vector>

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
  void get_lvl_order(TreeNode* root, int lvl, std::vector<std::vector<int>>& order_list) {
    if(root == nullptr) return;

    if(lvl + 1 > order_list.size()) order_list.push_back({root->val});
    else order_list[lvl].push_back(root->val);

    get_lvl_order(root->left, lvl+1, order_list);
    get_lvl_order(root->right, lvl+1, order_list);
  }

  std::vector<std::vector<int>> levelOrder(TreeNode* root) {
    std::vector<std::vector<int>> order_list;

    get_lvl_order(root, 0, order_list);

    return order_list;
  }
};