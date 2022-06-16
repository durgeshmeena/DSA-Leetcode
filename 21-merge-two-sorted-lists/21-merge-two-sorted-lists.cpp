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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*  merged;
        ListNode* tmp = new ListNode();
        
        merged = tmp;
        
        cout << tmp->val << "\n";
        
        while(list1 || list2){
            int val1 = list1?list1->val:INT_MAX;
            int val2 = list2?list2->val:INT_MAX;
            
            if(val2<val1){
                tmp->next = new ListNode(val2);
                list2 = list2->next;
            }
            else {
                tmp->next = new ListNode(val1);
                list1 = list1->next;
            }
            
            cout << tmp->val << " -> " ;
            
            tmp = tmp->next;
            
        }
        return merged->next;    
            
    }
};