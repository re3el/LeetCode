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
    ListNode* reverseList(ListNode *head)
    {
        ListNode *curr, *prev, *tmp;
        curr = head, prev = NULL;
        
        while(curr != NULL)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        if (head == NULL || head->next == NULL) return true;
        
        ListNode *slow, *fast, *tmp;
        slow = fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        tmp->next = NULL;
        
        // the length is odd; push to next number;
        if(fast != NULL)
            fast = slow->next;
        else
            fast = slow;
        
        slow = head;        
        fast = reverseList(fast);
            
        while(slow != NULL || fast != NULL)
        {
            if(slow == NULL || fast == NULL)
                return slow == fast;
            if(slow->val != fast->val)
                return false;
            
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};