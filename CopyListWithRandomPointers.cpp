/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) 
    {                  
        if(head == NULL) return head;
        
        RandomListNode *root, *tmp, *res;
        
        root = head;
        while(root != NULL)
        {
            RandomListNode* node = new RandomListNode(root->label);
            node->next = root->next;
            root->next = node;
            root = node->next;
        }    
        
        root = head;
        while(root != NULL)
        {
            if(root->random != NULL)
                root->next->random = root->random->next;
            root = root->next->next;
        }              
        
        root = head;    
        res = head->next;
        while(root != NULL)
        {
            tmp = root->next;
            if(root->next != NULL)
                root->next = root->next->next;
            root = tmp;
        }
        
        return res;
    }
};