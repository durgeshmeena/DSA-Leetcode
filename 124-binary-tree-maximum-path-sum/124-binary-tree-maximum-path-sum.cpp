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
    
    int ans=INT_MIN;
    
    int pathSum(TreeNode* root){
        if(!root) return 0;
        
        int lSum = pathSum(root->left);
        int rSum = pathSum(root->right);
        
        lSum = max(lSum, 0);
        rSum = max(rSum, 0);
        
        int val = root->val + max(lSum, rSum);
        
       ans = max(ans, root->val+lSum+rSum);
        
        return val;        
    }
    
    
    
    int maxPathSum(TreeNode* root) {

        int r = pathSum(root);
        
        return ans;
        
    }
};