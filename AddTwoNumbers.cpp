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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *tmp1, *tmp2, *head, *curr;
        tmp1 = l1;
        tmp2 = l2;
        head = new ListNode(0);
        curr = head;
        int sum = 0;
        int carry = 0;
        
        while(tmp1 != NULL || tmp2 != NULL)
        {
            sum = 0;
            if (tmp1 != NULL)    
            {
                sum += tmp1->val;
                tmp1 = tmp1->next;
            }
            if (tmp2 != NULL)    
            {
                sum += tmp2->val;
                tmp2 = tmp2->next;
            }
            sum += carry;
            carry = sum/10;
            sum = sum%10;
            cout<<"sum: "<<sum<<" ,carry: "<<carry<<endl;
            
            ListNode *newNode = new ListNode(sum);
            curr->next = newNode;
            curr = curr->next;                    
        }
        
        if (carry == 1)
        {
            ListNode *newNode = new ListNode(1);
            curr->next = newNode;
            curr = curr->next;                    
        }
            
        return head->next;
    }
};