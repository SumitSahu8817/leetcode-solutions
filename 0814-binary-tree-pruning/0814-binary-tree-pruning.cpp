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

    bool iop (TreeNode* node) {
        if(node==NULL) {
            return false;
        }
        if (node->val == 1) {
            return true;
        }
        return iop(node->left) || iop(node->right);

    }

    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) {
            return nullptr;
        }
        if (!iop(root->left)) {
            root->left = NULL;
        }
        if (!iop(root->right)) {
            root->right = NULL;
        }
        pruneTree(root->left);
        pruneTree(root->right);

        if (root->left == NULL && root->right == NULL &&root->val == 0) {
            return NULL;
        }

        return root;
    }
};