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
    int n;
    ListNode* solve(ListNode* head){
        if(head->next==NULL || head->next->next==NULL){
            n = 0;
            return head;
        }
        
        ListNode *n1 = head, *n2 = head->next, *nh = head->next->next;
        n1->next = NULL, n2->next = NULL;
        
        ListNode *r1 = solve(nh);
        n1->next = r1;
        int m = n;
        while(m--)
            r1 = r1->next;
        n2->next = r1->next;
        r1->next = n2;
        n++;
        
        return n1;
            
        
    }
    
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        
        return solve(head);
    }
};