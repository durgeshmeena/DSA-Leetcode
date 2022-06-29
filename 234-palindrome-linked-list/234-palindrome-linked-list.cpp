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
    
    ListNode* curr;
    bool isPalindrome(ListNode* head){
        curr = head;
        return check(head);
    }
    
    bool check(ListNode* tail){
        if(tail ==NULL)
            return true;
        bool r1 = check(tail->next) and (curr->val == tail->val); 
        curr = curr->next;
        return r1;
    }
    
//     bool isPalindrome(ListNode* head) {
//         ListNode *curr=head, *fast = head, *nxt;
        
//         while(fast->next && fast->next->next){
//             fast = fast->next->next;
//             nxt = curr->next;
//             curr->next = nxt->next;
//             nxt->next = head;
//             head = nxt;
            
//         }
//         if(!fast->next)
//             head = head->next;
//         curr = curr->next;
//         while(curr){
//             if(head->val != curr->val)
//                 return false;
            
//             head = head->next;
//             curr = curr->next;
//         }
//         return true;
        
//     }

};