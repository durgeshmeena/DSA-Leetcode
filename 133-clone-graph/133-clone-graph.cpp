/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*>nodes;
        queue<Node*>q;
        Node* nd;
        Node* newNode = NULL;
        if(node){
            newNode = new Node(node->val);
            nodes[node->val] = newNode;
            q.push(node);
        }
        Node* head = newNode;

        while(!q.empty()){
            nd = q.front();
            q.pop();
            for(auto x : nd->neighbors){
                if(!nodes[x->val]){
                    Node* newNode = new Node(x->val);
                    nodes[x->val] = newNode;
                    q.push(x);
                }
                nodes[nd->val]->neighbors.push_back(nodes[x->val]);
                    
            }
        }
        
        return head;
        
    }
};