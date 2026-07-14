/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    int isbal(TreeNode* root) {
        // height
        if (root == NULL) return 0;  // 0-0 = 0 balance

        int left = isbal(root->left);
        if (left == -1) return -1;  // left not balance

        int right = isbal(root->right);
        if (right == -1) return -1;  // right not balance

        // check condition
        if (abs(left - right) > 1) return -1;  // if not satisfy = (-1)

        return 1 + max(left, right);  // else height
    }
    bool isBalanced(TreeNode* root) { return (isbal(root) != -1); }
};
