#include<queue>
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
  template<typename Heap_T>
  void dfs(TreeNode* root, Heap_T& min_heap) {
    if(root == nullptr) return;

    min_heap.push(root->val);
    dfs(root->left, min_heap);
    dfs(root->right, min_heap);
  }

  int kthSmallest(TreeNode* root, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    dfs(root, min_heap);
    for(int i = 1; i < k; ++i) min_heap.pop();

    return min_heap.top();
  }
};