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
    
    ListNode* insert(ListNode* l, ListNode* list){
        if(list==NULL)
            return l;
        if( l->val <= list->val ){
            l->next = list;
            return l;
        }
            
        
        ListNode* node = list;
        ListNode* nxt = list->next;
        // node->next=NULL;
        
        node->next = insert(l, nxt);
        return node;
        
        
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if( list1==NULL or list2==NULL){
            return list1? list1 : ( list2 ? list2 : NULL );
        }
        
        ListNode* l1 = list1, *nl1 = list1->next;
        ListNode* l2 = list2, *nl2 = list2->next;
        // l1->next = NULL;
        // l2->next = NULL;
        
        ListNode* m = mergeTwoLists(nl1, nl2);
        
        ListNode* m1 = insert(l1, m);
        ListNode* m2 = insert(l2, m1);
        
        return m2;
        
        
    }
};