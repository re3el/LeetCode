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
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) 
    {
        if(root == NULL) return 0;
        calSum(root);
        return maxSum;
    }
    
    int calSum(TreeNode *root)
    {
        if(root == NULL) return 0;
        
        int rVal = root->val;
        int sum = rVal;        
        int leftSum = calSum(root->left);        
        int rightSum = calSum(root->right);
        
        sum = max(sum, max(sum+leftSum, max(sum+rightSum, sum+leftSum+rightSum)));        
        maxSum = max(maxSum,sum);
        sum = max(rVal,max(rVal+leftSum,rVal+rightSum));
        
        return sum;
    }
};