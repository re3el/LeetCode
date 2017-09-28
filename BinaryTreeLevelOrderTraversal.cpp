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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (root == NULL) return {};
        vector<vector<int>>res;
        queue<TreeNode*>que;        
        TreeNode *curr;        
        vector<int>level;
        
        que.push(root);
        que.push(NULL);
        while(!que.empty())
        {
            curr = que.front();
            que.pop();                        
            if(curr == NULL)
            {
                res.push_back(level);
                level.resize(0);
                if(!que.empty())
                    que.push(NULL);
            }
            else
            {
                level.push_back(curr->val);
                if(curr->left != NULL)
                    que.push(curr->left);
                if(curr->right != NULL)
                    que.push(curr->right);                
            }            
        }
        return res;
    }
};