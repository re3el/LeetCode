/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* convert(ListNode *head, ListNode *tail)
    {
        if(head == tail) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *node = new TreeNode(slow->val);
        node->left = convert(head,slow);
        node->right = convert(slow->next,tail);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head == NULL) return NULL;
        return convert(head,NULL);
    }
};