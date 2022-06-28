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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        
        ListNode *slow = head;
        ListNode *fast = slow->next;
        
        while(fast and slow != fast){
            slow = slow->next;
            if(fast->next)
                fast = fast->next->next;
            else
                return false;
        }
        if(fast==NULL)
            return false;
        return true;
        
    }
};