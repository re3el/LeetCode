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
        if (root == NULL) return;
        connectAgain(root->left,root->right);
    }
    
    void connectAgain(TreeLinkNode *node1, TreeLinkNode *node2)
    {
        // given its a perfect binary tree
        if(node1 == NULL || node2 == NULL) return;
        node1->next = node2;
        connectAgain(node1->left,node1->right);
        connectAgain(node1->right,node2->left);
        connectAgain(node2->left,node2->right);
    }
};