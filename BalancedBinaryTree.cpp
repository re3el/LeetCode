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
    int checkHeightBalance(TreeNode *node)
    {
        if (node == NULL) return 0;
        
        int leftH = checkHeightBalance(node->left);
        if(leftH == -1) return -1;
        
        int rightH = checkHeightBalance(node->right);
        if(rightH == -1) return -1;
        
        if(abs(leftH-rightH) > 1) return -1;
        
        return 1 + max(leftH,rightH);
    }
    
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL) return true;        
        return checkHeightBalance(root) != -1;
    }
};