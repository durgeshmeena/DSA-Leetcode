/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public: 
    Node* flatten(Node* head) {
        if(!head )
            return NULL;
        
        Node *nn2 = flatten(head->next);
        Node *nn1 = flatten(head->child);
    
        head->next = NULL, head->child = NULL;
        
        if(nn1){
            head->next = nn1;
            nn1->prev = head;
        }
            
        nn1 = head;
        while(nn1->next)
            nn1 = nn1->next;
        
        if(nn2){
            nn1->next = nn2;
            nn2->prev = nn1;
        }
        return head;
        
    }
};