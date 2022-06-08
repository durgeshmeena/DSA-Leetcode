class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        
        for(auto x:prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int>inDegree(n);
        for(int i=0;i<n;i++)
                for(auto j:adj[i])
                    inDegree[j]++;
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)
                q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            
            int u=q.front();
            q.pop();
            cnt++;
            
            for(auto v:adj[u]){
                inDegree[v]--;
                if(inDegree[v]==0)
                    q.push(v);
            }
        }
        
        if(cnt==n)
            return true;
        return false;
        
        
    }
};