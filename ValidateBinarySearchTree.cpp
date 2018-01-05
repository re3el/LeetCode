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
    bool check(TreeNode* node, TreeNode* low, TreeNode* high)
    {
        if(node == NULL) return true;
        if((high && node->val >= high->val) || (low && node->val <= low->val)) return false;
        
        return check(node->left,low,node) && check(node->right,node,high);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        if(root == NULL) return true;
        return check(root,NULL,NULL);
    }
};