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
    int low;
    int high;
    TreeNode* help(TreeNode* root)
    {
        if (root == NULL)
            return NULL;

        // if(root->left==NULL and root->right==NULL ){
        //     if (root->val >= low and root->val <= high)return root;
        //     return NULL;
        // }
        
        if ( root->val < low)
            root = help(root->right);
        else if (root->val > high)
            root = help(root->left);
        if (root){
            root->left = help(root->left);
            root->right = help(root->right);
        }

        return root;

        
    }
    
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        this->low = low;
        this->high = high;
        return help(root);
        
    }
};