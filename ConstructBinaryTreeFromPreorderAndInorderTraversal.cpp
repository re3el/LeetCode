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
    int n;
public:
    TreeNode* computeTree(vector<int>& preorder, vector<int>& inorder, int lowP, int lowI, int highI) 
    {
        if(lowI > highI || lowP == n) return NULL;
        TreeNode* root = new TreeNode(preorder[lowP]);
        int cnt = 0;
        for(int i=lowI; i<highI; i++)
        {
            if(inorder[i] == preorder[lowP])
                break;
            cnt++;
        }
        root->left = computeTree(preorder,inorder,lowP+1,lowI,lowI+cnt-1);
        root->right = computeTree(preorder,inorder,lowP+1+cnt,lowI+cnt+1,highI);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        // assuming tree structure to be valid; preorder && inorder size to be same;
        n = preorder.size();        
        if(n == 0) return NULL;            
        
        return computeTree(preorder,inorder,0,0,n-1);                
    }        
};