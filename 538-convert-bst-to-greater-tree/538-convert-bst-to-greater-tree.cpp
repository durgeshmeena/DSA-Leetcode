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
    int prev = 0;
    int helper(TreeNode* root) {
        if (root == NULL)
            return prev;
        
        prev = helper(root->right);
        root->val += prev;
        prev = root->val;
        
        if (root->left){
            prev = helper(root->left);
        }
        return prev;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int val = helper(root);
        return root;
    }
};