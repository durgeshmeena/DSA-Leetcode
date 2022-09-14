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
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode *cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode *lNode = cur->left;
                while(lNode->right != NULL) lNode = lNode->right;
                lNode->right = cur;
                TreeNode *tmp = cur;
                
                cur = cur->left;
                tmp->left = NULL;
            }
        }
        
        return inorder;
    }
};