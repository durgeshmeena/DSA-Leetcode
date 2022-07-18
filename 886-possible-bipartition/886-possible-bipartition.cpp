class Solution {
public:
    
    bool bipartite(int i, int val, vector<int>& color, vector<vector<int>>& adj){
        color[i] = val;
        for(auto next:adj[i]){
            if(color[next]==INT_MAX && !bipartite(next, val^1, color, adj)){
                cout << i << "-> " << "False\n";
                return false;
            }
                
            else if(color[next]==val){
                cout << i << "-> " << "False\n";
                return false;
            }
                
        }
        cout << i << "-> " << "True\n";
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1, INT_MAX);
        vector<vector<int>>adj(n+1);
        
        for(auto v:dislikes){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        for(int i=1; i<=n; i++){
            if(color[i]==INT_MAX && !bipartite(i, 0, color, adj))
                return false;
        }
   
        return true;
        
    }
};