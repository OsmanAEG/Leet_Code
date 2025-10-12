// LeetCode: 100

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
  bool is_same = true;

  void check_same(TreeNode* root1, TreeNode* root2) {
    if(is_same == false) return;
    if(root1 == nullptr && root2 == nullptr) return;

    if(root1 == nullptr && root2 != nullptr) {
      is_same = false;
      return;
    } else if (root1 != nullptr && root2 == nullptr) {
      is_same = false;
      return;
    } else if (root1->val != root2->val){
      is_same = false;
      return;
    }

    check_same(root1->left,  root2->left);
    check_same(root1->right, root2->right);
  }

  bool isSameTree(TreeNode* p, TreeNode* q) {
    check_same(p, q);

    return is_same;
  }
};