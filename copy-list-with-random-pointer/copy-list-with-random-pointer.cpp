/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        
        unordered_map<Node*, Node*> adrs;
        
        Node *ohead = head;
        Node *prev = new Node(head->val), *curr;
        adrs[ohead] = prev;
        Node *nhead = prev;
        
        head = head->next;
        while(head){
            curr = new Node(head->val);
            prev->next = curr;
            adrs[head] = curr;
            
            head = head->next;
            prev = curr;
        }
        
        while(ohead){
            adrs[ohead]->random = adrs[ohead->random];
            ohead = ohead->next;
        }
        
        return nhead;
        
    }
};