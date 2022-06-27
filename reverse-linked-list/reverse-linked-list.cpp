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

    
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
            
        
        ListNode* n1 = head, *n2 = head->next; 
        head->next = NULL;
        n2 = reverseList(n2);
        ListNode* nhead = n2;
        
        // cout << n2->val <<" "<<nhead->val<<"\n";
        
        
        while(n2->next != NULL){
            n2 = n2->next;
        }
        n2->next = n1;
        
        // cout << n1->val <<" "<<n2->val << "\n";

        
        return nhead;
        
    }
};