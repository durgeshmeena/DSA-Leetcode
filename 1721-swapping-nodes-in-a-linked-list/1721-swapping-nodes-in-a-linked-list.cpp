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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* p = NULL;

        int v1,v2;
        int n = 1;
        while (fast) {            
            if (fast->next){
                if (fast->next->next){
                    n+=2;
                    fast = fast->next->next;
                }
                else {
                    n+=1;
                    fast = fast->next;
                }
            }
            else 
                fast = fast->next;
            
        }
    
        v1 = min(k, n-k+1);
        v2 = max(k, n-k+1);
        
        ListNode* tmp = head;
        
        for (int i=1; i<= v2; i++){
            
            if (i == v1)p = tmp;
            if (i == v2) {
                int v = tmp->val;
                tmp->val = p->val;
                p->val = v;
                break;
            }
            tmp = tmp->next;
            
        }
        
        return head;
        
        
        
        
    }
};