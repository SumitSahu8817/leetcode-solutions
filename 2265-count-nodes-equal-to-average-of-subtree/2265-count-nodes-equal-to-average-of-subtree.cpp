class Solution {
public:

    int ans = 0;

    pair<int, int> getSum(TreeNode* root) {
        if (root == NULL) {
            return {0, 0};
        }

        pair<int, int> left = getSum(root->left);
        pair<int, int> right = getSum(root->right);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        return {sum, count};
    }

    void traverse(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        pair<int, int> p = getSum(root);

        int sum = p.first;
        int count = p.second;

        if (sum / count == root->val) {
            ans++;
        }

        traverse(root->left);
        traverse(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        traverse(root);
        return ans;
    }
};