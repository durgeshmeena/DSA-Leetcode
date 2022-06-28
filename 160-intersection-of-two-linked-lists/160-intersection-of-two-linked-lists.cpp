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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == headB)
            return headA;
        
        ListNode * slow = headA;
        ListNode * fast = headA;
        int counter = 0;
        
        while(true){
            slow = slow->next;
            if(!slow){
                slow = headB;
                counter++;
            }
            fast = fast->next;
            if(!fast)fast = headB;
            fast = fast->next;
            if(!fast)fast = headB;
            
            if(slow==fast)
                break;
            if(counter==3)
                return NULL;
        }
        
        fast = headA;
        while(slow != fast){
            slow = slow->next;
            if(!slow)slow = headB;
            fast = fast->next;
            if(!fast)fast = headB;
            
        }
        fast = headA;
        while(fast != slow){
            fast = fast->next;
            if(!fast)return NULL;
        }
        
        return slow;
        
        
        
    }
};