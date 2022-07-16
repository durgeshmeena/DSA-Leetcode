class Solution {
public:
    
    
    int DFS(int cur, vector<int>& informTime, vector<vector<int>>& adj){
        if(adj[cur].size()==0)
            return 0;
        int mt = 0;
        for(auto next:adj[cur]){
            mt = max(mt, DFS(next, informTime, adj));
        }
        return informTime[cur] + mt;
    }
    
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n+1);
        
        manager[headID] = n;
        
        for(int i=0; i<n; i++){
            adj[manager[i]].push_back(i);
        }
        adj.pop_back();
        
        return DFS(headID, informTime, adj);
        
        
    }
};