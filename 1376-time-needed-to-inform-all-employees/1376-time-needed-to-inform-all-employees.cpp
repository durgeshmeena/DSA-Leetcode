class Solution {
public:
 
    int dfs(int u, vector<vector<int>>& adj, vector<int>& informTime, vector<bool>&vis){
        vis[u]=true;
        
        int tChild=0;
        for(auto it:adj[u])
            if(!vis[it])
               tChild = max(tChild, dfs(it,adj,informTime,vis));     
                
        return informTime[u]+tChild;
        
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n+1);
        vector<bool>vis(n+1);
        
        manager[headID]=n;
        for(int i=0; i<n; i++){
            // if(i!=headID)
                adj[manager[i]].push_back(i);
        }
        
        
        // for(int i=0; i<n; i++){
        //     cout << i << " -> ";
        //     for(auto it:adj[i])
        //         cout << it << " ";
        //     cout <<"\n";
        // }
        
        
        return  dfs(headID, adj, informTime, vis);
    }
};