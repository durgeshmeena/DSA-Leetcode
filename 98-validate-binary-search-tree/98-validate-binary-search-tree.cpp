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

    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        return valid(root, 1ll*INT_MAX+1, 1ll*INT_MIN-1);
    }
    
    bool valid(TreeNode* root, long maxVal, long minVal){
        if(!root)
            return true;
        
        if(root->val >= maxVal || root->val <= minVal) return false;
        
        return valid(root->left, root->val, minVal) and valid(root->right, maxVal, root->val);
    }
};