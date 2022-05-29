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
    
    int dia(TreeNode* root, int &d){
        if(!root)
            return 0;
        int lh = dia(root->left, d);
        int rh = dia(root->right, d);
        
        d = max(d, lh+rh);
        
        return 1+max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int d=INT_MIN;
        int diam = dia(root,d);
        return d;
    }
};