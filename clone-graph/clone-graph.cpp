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
    
    unordered_map<int, Node*>visted;
    
    void DFS(Node* node, Node* parent){
        
        for(auto child : node->neighbors){
            if(!visted[child->val]){
                auto nchild = new Node(child->val);
                visted[child->val] = nchild;
                DFS(child, nchild);    
            }
            parent->neighbors.push_back(visted[child->val]);
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        
        Node* nroot = new Node(1);
        visted.insert({1, nroot});
        DFS(node, nroot);
        
        return nroot;
        
    }
};