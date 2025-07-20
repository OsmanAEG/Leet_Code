#include<algorithm>
#include<vector>

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
  long long kthLargestLevelSum(TreeNode* root, int k) {
    auto node = root;
    std::vector<long long> level_sum;
    add_level_sum(node, 0, level_sum);

    std::sort(level_sum.begin(), level_sum.end());

    if(k >= level_sum.size()) return -1;
    return level_sum[level_sum.size() - k];
  }

  template<typename Vector_T>
  void add_level_sum(TreeNode* node, int level, Vector_T& level_sum) {
    while(level_sum.size() <= level) level_sum.push_back(0);

    if(node != nullptr) {
      level_sum[level] += node->val;
      add_level_sum(node->left, level + 1, level_sum);
      add_level_sum(node->right, level + 1, level_sum);
    }
  }
};

int main() {
  return 0;
}