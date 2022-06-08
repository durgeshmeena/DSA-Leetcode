class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        queue<int>q;
        vector<int>indegree(n);
        vector<int>topo(n);
        
        for(auto x:prerequisites)
            adj[x[1]].push_back(x[0]);
        
        
        for(int u=0;u<n;u++){
            for(auto v:adj[u])
                indegree[v]++;
        }
        
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
                q.push(i);
        
        int cnt=0;
        int k=0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo[k++]=u;
            cnt++;
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)
                    q.push(v);
            }
        }
        
        if(cnt==n)
            return topo;
        
        return {};
        
        
        
        
    }
};