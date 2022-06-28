/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        if(!head)
            return NULL;
        
        ListNode *curr = head, *nxt; 
        while(curr->next){
            nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = head;
            head = nxt;  
        }
        
        return head;
    }
    
//     ListNode* reverseList(ListNode* head) {
//         if(head==NULL || head->next == NULL)
//             return head;
        
//         ListNode* n1 = head, *nhead = head->next;
//         n1->next = NULL;
//         ListNode* n2 = reverseList(nhead);
//         ListNode* tmp = n2;
//         while(tmp->next != NULL)
//             tmp = tmp ->next;
//         tmp->next = n1;
        
//         return n2;
        
//     }

};