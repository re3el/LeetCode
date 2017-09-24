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
    ListNode* mergeList(ListNode* node1, ListNode* node2)
    {
        ListNode *head, *curr, *node; 
        head = new ListNode(0);
        curr = head;
        
        while(node1 != NULL && node2 != NULL)
        {
            if(node1->val > node2->val)
            {
                node = new ListNode(node2->val);
                node2 = node2->next;
            }
            else
            {
                node = new ListNode(node1->val);
                node1 = node1->next;
            }
            curr->next = node;
            curr = curr->next;
        }
        if (node1 != NULL)
            curr->next = node1;
        if (node2 != NULL)
            curr->next = node2;
        
        return head->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode *curr, *slow, *fast, *l1, *l2;
        slow = fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            curr = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        curr->next = NULL;
        fast = slow;
        slow = head;
        l1 = sortList(slow);
        l2 = sortList(fast);
        return mergeList(l1,l2);        
    }
};