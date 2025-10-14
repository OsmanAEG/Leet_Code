// LeetCode: 572

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
  bool found_subtree = false;

  void find_subtree(TreeNode* root, TreeNode* subRoot, bool& same) {
    if(root == nullptr && subRoot == nullptr) {
      return;
    } else if(root == nullptr && subRoot != nullptr) {
      same = false;
      return;
    } else if(root != nullptr && subRoot == nullptr) {
      same = false;
      return;
    } else if(root->val != subRoot->val) {
      same = false;
      return;
    }

    find_subtree(root->left,  subRoot->left,  same);
    find_subtree(root->right, subRoot->right, same);
  }

  void find_node(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr) return;

    if(root->val == subRoot->val) {
      bool same = true;
      find_subtree(root, subRoot, same);

      if(same) {
        found_subtree = true;
        return;
      }
    }

    find_node(root->left,  subRoot);
    find_node(root->right, subRoot);
  }

  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    find_node(root, subRoot);
    return found_subtree;
  }
};