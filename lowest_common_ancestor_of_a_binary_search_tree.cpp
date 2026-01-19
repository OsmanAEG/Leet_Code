// LeetCode: 235

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  TreeNode* lca;

  void find_ancestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) return;

    if(root->val >= p->val && root->val <= q->val) lca = root;

    if(root->val < p->val) find_ancestor(root->right, p, q);
    if(root->val > q->val) find_ancestor(root->left, p, q);
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p->val > q->val) find_ancestor(root, q, p);
    else find_ancestor(root, p, q);

    return lca;
  }
};