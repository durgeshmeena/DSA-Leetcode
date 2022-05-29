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
    
//     int sum(TreeNode* root){
//         if(!root)
//             return 0;
//         if(!root->left and !root->right){
//             return root->val;
//         }
//         else if(root->left and root->right)
//             return root->val + sum(root->left) + sum(root->right);
        
//         return root->val +( (root->left)?sum(root->left):sum(root->right) );
//     }
    
    // int findTilt(TreeNode* root) {
    //     if(!root)
    //         return 0;
    //     return abs(sum(root->left) - sum(root->right)) + findTilt(root->left) + findTilt(root->right);
    // }
    
    
    int tilt=0;
    int findTilt(TreeNode* root){
        int d = DFS(root);
        return tilt;
    }
    
    int DFS(TreeNode* root){
        if(!root)
            return 0;
        int ls = DFS(root->left);
        int rs = DFS(root->right);
        tilt += abs(ls-rs);
        return root->val + ls + rs;
    }
    
    
    
    
    
    
    
    
};