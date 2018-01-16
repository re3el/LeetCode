/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;  
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int res;
public:
    int univaluePath(TreeNode* node)
    {
        if(node == NULL) return 0;                
        int lval = 0, rval = 0;
        
        if(node->left){            
            lval = univaluePath(node->left);            
            if(node->left->val == node->val) lval++;
            else lval = 0;
        }
        
        if(node->right){
            rval = univaluePath(node->right);
            if(node->right->val == node->val) rval++;
            else rval = 0;
        }        
        
        res = max(res,lval+rval);        
        return max(lval,rval);
    }
    
    int longestUnivaluePath(TreeNode* root) 
    {
        if(root == NULL) return 0;
        res = INT_MIN;
        univaluePath(root);
        return res;
    }
};