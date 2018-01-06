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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int &pInd, int iBeg, int iFin) 
    {
        if(pInd == postorder.size() || iBeg > iFin) return NULL;
        TreeNode* node = new TreeNode(postorder[pInd]);
        int i;
		
		// a better way of search would be to use a hashmap[inorderValue]->index, initialized before calling build
        for(i=iBeg; i<=iFin; i++)
            if(inorder[i] == postorder[pInd])
                break;
        pInd++;
        node->right = build(inorder,postorder,pInd,i+1,iFin);
        node->left = build(inorder,postorder,pInd,iBeg,i-1);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {        
		// check if inorder and postorder are of same size; assuming these two to be valid!
        reverse(postorder.begin(),postorder.end());
        int pInd = 0;
        return build(inorder,postorder,pInd,0,inorder.size()-1);
    }
};