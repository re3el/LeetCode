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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (head == NULL)
            return head;
        
        ListNode *odd, *even, *evenHead;
        odd = head;
        even = head->next;
        evenHead = head->next;
        
        while(even != NULL && even->next != NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;            
        }
        
        odd->next = evenHead;
        return head;
    }
};