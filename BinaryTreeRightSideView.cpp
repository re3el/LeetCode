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
    void compute(TreeNode* root, vector<int> &res, int level)
    {
        if(root == NULL) return;
        if(res.size() < level) res.push_back(root->val);
        compute(root->right,res,level+1);
        compute(root->left,res,level+1);
    }
    
    vector<int> rightSideView(TreeNode* root)
    {        
        vector<int> res;
        compute(root,res,1);       
        return res;
    }
};