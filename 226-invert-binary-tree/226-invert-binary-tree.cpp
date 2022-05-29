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
        
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* node1 = new TreeNode();
        TreeNode* node2 = new TreeNode();

        node1 = invertTree(root->right);
        node2 = invertTree(root->left);    
        root->left = node1;
        root->right = node2;
        return root;
    }
};