class Solution {
public:
    vector<int> ans;
    
    bool DFS(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node]=1;
        for(auto next:adj[node]){
            if(!vis[next] && !DFS(next, vis, adj))
                return false;
            else if(vis[next]==1)
                return false;
        }
        vis[node]=2;
        ans.push_back(node);
        return true;
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n = numCourses;
        vector<int> vis(n);
        vector<vector<int>> adj(n);
        
        for(auto v:prerequisites){
            adj[v[1]].push_back(v[0]);
            
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i] && !DFS(i, vis, adj) )
                return {};
        }
            
        
        reverse(ans.begin(), ans.end());
        return ans;
        
        
    }
    
    
    
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         int n= numCourses;
//         vector<int>crs;
//         vector<vector<int>> adj(n);
//         vector<int>indegree(n);
//         for(auto v:prerequisites){
//             adj[v[1]].push_back(v[0]);
//             indegree[v[0]]++;
//         }
        
//         queue<int> q;
        
//         for(int i=0; i<n; i++)
//             if(indegree[i]==0)q.push(i);
        
//         while(q.size()){
//             int node = q.front(); q.pop();
//             crs.push_back(node);
//             for(auto next:adj[node]){
//                 indegree[next]--;
//                 if(indegree[next]==0)q.push(next);
//             }
//         }
        
//         if(crs.size()!=n)
//             return {};
//         return crs;

        
//     }
    
};