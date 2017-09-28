/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> stk;
public:
    BSTIterator(TreeNode *root) 
    {
        add_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() 
    {
        TreeNode *res = stk.top();        
        stk.pop();
        if(res->right != NULL)
            add_left(res->right);        
        return res->val;
    }
    
    void add_left(TreeNode *node)
    {
        while(node != NULL)
        {
            stk.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */