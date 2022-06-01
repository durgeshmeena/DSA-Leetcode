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
    unordered_map<Node*, Node*>nodes;
    
    Node* dfs(Node* node){
        nodes[node] = new Node(node->val);
        for(auto it:node->neighbors){
            if(!nodes[it])
                nodes[node]->neighbors.push_back(dfs(it));
            else
                nodes[node]->neighbors.push_back(nodes[it]);
        }
        return nodes[node];
        
    }
    
    
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        return dfs(node);
    }
    
    
//     Node* cloneGraph(Node* node) {
//         unordered_map<int, Node*>nodes;
//         queue<Node*>q;
//         Node* nd;
//         Node* newNode = NULL;
//         if(node){
//             newNode = new Node(node->val);
//             nodes[node->val] = newNode;
//             q.push(node);
//         }
//         Node* head = newNode;

//         while(!q.empty()){
//             nd = q.front();
//             q.pop();
//             for(auto x : nd->neighbors){
//                 if(!nodes[x->val]){
//                     Node* newNode = new Node(x->val);
//                     nodes[x->val] = newNode;
//                     q.push(x);
//                 }
//                 nodes[nd->val]->neighbors.push_back(nodes[x->val]);
                    
//             }
//         }
        
//         return head;
        
//     }
};