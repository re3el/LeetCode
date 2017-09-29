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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return NULL;
        return fillBST(nums,0,n);
    }
    
    TreeNode* fillBST(vector<int>& nums, int start, int end)
    {
        if(start >= end) return NULL;
        
        int mid = (start + end)/2;        
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = fillBST(nums,start,mid);
        node->right = fillBST(nums,mid+1,end);
        
        return node;
    }
};