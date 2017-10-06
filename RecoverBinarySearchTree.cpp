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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
public:
    void inorder(TreeNode* node)
    {
        if(node == NULL) return;
        inorder(node->left);
        if(first == NULL && node->val < prev->val)
            first = prev;
        if(first != NULL && node->val < prev->val)
            second = node;
        prev = node;
        inorder(node->right);
    }
    
    void recoverTree(TreeNode* root) 
    {
        inorder(root);
        swap(first->val,second->val);
    }
};