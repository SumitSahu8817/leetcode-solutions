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

    string get (TreeNode* root , unordered_map<string , int> &mp , vector<TreeNode*> &v ) {
            if (root == NULL) {
                return "N";
            }
            string s = to_string(root->val) + "," + get(root->left , mp , v) + "," + get(root->right , mp , v);

            if(mp[s]==1) {
                v.push_back(root);
            }
            mp[s]++;
            return s;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map < string , int > mp;
        vector <TreeNode*> v;
        get (root , mp , v);
        return v; 
    }
};