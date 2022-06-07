class Solution {
public:
    
    
//     bool dfs(int u, int color, vector<vector<int>>& adj, vector<int>& col) {
        
//         col[u] = color;
        
//         for(auto v : adj[u]){
//             if(col[v]==-1){
//                if(!dfs(v,color^1, adj, col))return false; 
//             }
//             else
//                 if(color == col[v]) return false;
            
//         }

//         return true;
        
//     }
    
//     bool isBipartite(vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int>col(n, -1);
        
//         for(int i=0; i<n; i++)
//             if(col[i]==-1)
//                 if(!dfs(i,0, adj, col)) return false;
                
        
//         return true;
//     }
    
    
    
    vector<int>parent;
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        for(int i=0; i<n;i++)
            for(int j=0; j<adj[i].size(); j++) {
                if(find(i)==find(adj[i][j]))
                    return false;
                uni(adj[i][0],adj[i][j]);
            }
        
        return true;
        
    }
    
    
    
    int find(int u){
        if(parent[u]==u)return u;
        else{
            return parent[u] = find(parent[u]);
        }
    }
    
    void uni(int u, int v){
        int up = find(u);
        int vp = find(v);
        if(up!=vp)
            parent[vp]=up;
    }
    
    
};