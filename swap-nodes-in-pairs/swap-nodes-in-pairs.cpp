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
    ListNode* swapPairs(ListNode* node) {
        if(node==NULL || node->next==NULL){
            return node;
        }    
        
        ListNode* n1 = node;
        ListNode* n2 = node->next;
  
        n1->next = swapPairs(n2->next);
        n2->next = n1;
        return n2;
        
    }
};