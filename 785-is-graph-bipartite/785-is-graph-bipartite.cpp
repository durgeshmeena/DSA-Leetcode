class Solution {
public:
    
    
    bool dfs(int u, int color, vector<vector<int>>& adj, vector<int>& col) {
        
        col[u] = color;
        
        bool f=true;
        for(auto v:adj[u]){
            if(col[v]==-1)
                f = f and dfs(v,color^1, adj, col);
            else{
                if(color == col[v]) return false;
            }
        }

        return f;
        
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>col(n, -1);
        
        bool flag=true;
        for(int i=0; i<n; i++){
            if(col[i]==-1)
                flag = flag and dfs(i,0, adj, col);
        }
        
        for(auto c:col)
            cout << c << " ";
        

        
        return flag;
    }
};