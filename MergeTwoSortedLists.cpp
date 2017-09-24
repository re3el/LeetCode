/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *tmp1, *tmp2, *head, *curr, *newNode;
        tmp1 = l1;
        tmp2 = l2;
        head = new ListNode(0);
        curr = head;
        
        while(tmp1 != NULL && tmp2 != NULL)
        {            
            if (tmp1->val > tmp2->val)
            {
                newNode = new ListNode(tmp2->val);                
                tmp2 = tmp2->next;
            }
            else
            {
                newNode = new ListNode(tmp1->val);
                tmp1 = tmp1->next;
            }
            curr->next = newNode;
            curr = curr->next;
        }
        if (tmp1 != NULL)        
            curr->next = tmp1;        
        if (tmp2 != NULL)
            curr->next = tmp2;
        
        return head->next;
    }
};