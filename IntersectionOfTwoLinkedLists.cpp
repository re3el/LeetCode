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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (headA == NULL || headB == NULL)    
            return NULL;
        
        ListNode *a, *b;
        a = headA;
        b = headB;
        
        while(a != b)
        {
            a = a->next;
            b = b->next;
            
            if(a == b) return a;                            
            if(a == NULL) a = headB;
            if(b == NULL) b = headA;
        }
        return a;
    }
};