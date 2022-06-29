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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
            return NULL;
        
        int len=0;
        ListNode *tmp = head, *last;
        while(tmp){
            len++;
            last = tmp;
            tmp = tmp->next;
        }
        int back = k%len;
        int front = len - back;
        
        tmp = head;
        while(--front){
            tmp = tmp->next;
        }
        last->next = head;
        head = tmp->next;
        tmp->next = NULL;
        
        return head;
    }
};