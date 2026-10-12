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
    vector<double> averageOfLevels(TreeNode* root) {
         vector <double> v;
        if (root == NULL) return v;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
       
         if (root == NULL) return v;
        while (!q.empty()) {
                double sum = 0;
                int nodes = 0;
                while (q.front()!=NULL) {
                    TreeNode* node = q.front();
                    q.pop();
                    sum += node->val;
                    nodes++;
                    if (node->left != NULL)q.push(node->left);
                    if (node->right!=NULL) q.push(node->right);
                    
                }
               q.pop();
                v.push_back(sum/nodes);
                if (!q.empty()) {
                    q.push(NULL);
                }
        }
        return v;
    }
};