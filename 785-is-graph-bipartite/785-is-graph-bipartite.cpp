class Solution {
public:
    
    bool bipartite(int i, int val, vector<int>& color, vector<vector<int>>& adj){
        color[i] = val;
        for(auto next:adj[i]){
            if(!color[next] && !bipartite(next, -val, color, adj))
                return false;
            else if(color[next]==val)
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n);
        for(int i=0; i<n; i++){
            if(!color[i] && !bipartite(i, 1, color, graph))
                return false;
        }
        return true;
    }
};