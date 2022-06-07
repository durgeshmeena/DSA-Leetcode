class Solution {
public:
    
    
    vector<int>cyl;
    
    bool inCycle(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& dfsvis) {
        if(cyl[node]==1)return cyl[node];
        
        vis[node]=true;
        dfsvis[node]=true;
        for(auto v:adj[node]){
            if(!vis[v]){
                if(inCycle(v,adj,vis,dfsvis))
                    return cyl[node] = 1;         
            }
            else
                if(dfsvis[v])return cyl[node]=1;    
            
                
        }
        
        dfsvis[node]=false;    
        return cyl[node] = false;
        
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool>vis(n);
        vector<bool>dfsvis(n);
        cyl.resize(n);
        
        for(int i=0;i<n;i++)
            if(!vis[i])
                bool a = inCycle(i,adj,vis,dfsvis);
        
        vector<int>ans;
            
        for(int i=0;i<n;i++)
                if(!cyl[i])ans.push_back(i);
        
        sort(ans.begin(), ans.end());
        
        return ans;
            
        
        
    }
};