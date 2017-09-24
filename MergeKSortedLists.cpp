/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct compare
    {
        bool operator()(const ListNode* l1, const ListNode* l2)    
        {
            return l1->val > l2->val;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto i:lists)
        {
            if (i != NULL)
                pq.push(i);
        }
        
        ListNode *head, *curr;
        head = new ListNode(0);
        curr = head;
        while(!pq.empty())
        {
            curr->next = pq.top();
            pq.pop();
            curr = curr->next;
            if(curr->next != NULL)
                pq.push(curr->next);                
        }
        return head->next;
    }
};