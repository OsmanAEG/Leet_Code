#include<algorithm>
#include<set>

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
  void dfs(TreeNode* root, std::set<int>& unique_vals) {
    if(root == nullptr) return;

    unique_vals.insert(root->val);

    dfs(root->left,  unique_vals);
    dfs(root->right, unique_vals);
  }

  int getMinimumDifference(TreeNode* root) {
    int min = 1E6;
    std::set<int> unique_vals;

    dfs(root, unique_vals);

    auto low  = unique_vals.begin();
    auto high = unique_vals.begin();

    ++high;

    while(high != unique_vals.end()) {
      min = std::min(min, std::abs(*high - *low));
      ++low;
      ++high;
    }

    return min;
  }
};