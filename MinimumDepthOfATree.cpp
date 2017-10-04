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
public:
    int minDepth(TreeNode* root) 
    {
        if(root == NULL) return 0;      
        if(root->left == NULL && root->right == NULL) return 1;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left == NULL) return 1+right;
        else if(root->right == NULL) return 1+left;
        else return 1+min(left,right);
    }
};