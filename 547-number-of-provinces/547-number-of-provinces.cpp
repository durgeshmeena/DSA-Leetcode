class Solution {
public:
    
    void dfs(int u, vector<int>adj[], vector<int>&vis){
        vis[u] = 1;
        for(auto v:adj[u]){
            if(!vis[v])
                dfs(v, adj, vis);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+1];
        vector<int>vis(n+1);
        
        
        for(int i=0; i<isConnected.size(); i++)
            for(int j=0; j<isConnected[0].size(); j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        int prov=0;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                dfs(i, adj, vis);
                prov++;
            }
                
        }
        
        return prov;
    }
};