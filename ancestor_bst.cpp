// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  void dfs(TreeNode* root, int& min_val, int& max_val, TreeNode*& ancestor) {
    if(root == nullptr) return;

    if(root->val > max_val) dfs(root->left, min_val, max_val, ancestor);
    else if(root->val < min_val) dfs(root->right, min_val, max_val, ancestor);
    else ancestor = root;
  }

  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* ancestor;

    if(p->val < q->val) dfs(root, p->val, q->val, ancestor);
    if(p->val > q->val) dfs(root, q->val, p->val, ancestor);

    return ancestor;
  }
};