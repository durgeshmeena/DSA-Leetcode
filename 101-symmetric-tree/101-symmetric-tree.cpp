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
    
    bool mirror(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL)
           return p==q;
        return (p->val == q->val and mirror(p->left, q->right) and mirror(q->left, p->right));
    }
    
    bool isSymmetric(TreeNode* root) {
        return mirror(root->left, root->right);
    }
};