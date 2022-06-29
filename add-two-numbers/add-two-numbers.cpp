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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *prev, *head=l1; 
        
        while(l1 and l2){
            prev = l1;
            int val = l1->val + l2->val + carry;
            if(val > 9){
                l1->val = val%10;
                carry = val/10;
            }else{
                l1->val = val;
                carry = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
        
        }
        if(!l1)
            prev->next = l2;
        l1 = prev->next;
        
        while(l1){
            prev = l1;
            int val = l1->val + carry;
            if(val > 9){
                l1->val = val%10;
                carry = val/10;
            }else{
                l1->val = val;
                carry = 0;
            }
            l1 = l1->next;
        }
        if(carry)
            prev->next = new ListNode(carry);
        
        return head;
        
        
        
    }
};