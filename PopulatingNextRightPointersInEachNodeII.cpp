/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if(root == NULL) return;
        TreeLinkNode *tmpChild = new TreeLinkNode(0);
        while(root)
        {
            TreeLinkNode *currChild = tmpChild;
            while(root)
            {
                if(root->left)
                {
                    currChild->next = root->left;
                    currChild = currChild->next;                    
                }
                if(root->right)
                {
                    currChild->next = root->right;
                    currChild = currChild->next;
                }
                root = root->next;
            }
            root = tmpChild->next;
            tmpChild->next = NULL;
        }
    }
};