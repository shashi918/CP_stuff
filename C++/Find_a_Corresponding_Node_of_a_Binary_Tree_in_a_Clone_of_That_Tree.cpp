#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                        TreeNode *target) {
  if (cloned == nullptr) {
    return NULL;
  }
  if (target->val == cloned->val) {
    return cloned;
  }
  TreeNode *left = getTargetCopy(original, cloned->left, target);
  TreeNode *right = getTargetCopy(original, cloned->right, target);
  if (left != nullptr)
    return left;
  else
    return right;
}

int main() {
  {
    TreeNode *node = new TreeNode(
        7, new TreeNode(4), new TreeNode(3, new TreeNode(6), new TreeNode(19)));
    TreeNode *copyNode = new TreeNode(
        7, new TreeNode(4), new TreeNode(3, new TreeNode(6), new TreeNode(19)));
    TreeNode* temp = new TreeNode(19);
    TreeNode *ans = getTargetCopy(node, copyNode, temp);
    cout<<ans->val;
        }
}