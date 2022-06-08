class Solution {
public:
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        queue<int>q;
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto x:times){
           adj[x[0]].push_back({x[1],x[2]}); 
        }
        
     
        dist[k]=0;
        q.push(k);
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            for(auto trg:adj[node]){
                if(dist[trg.first] > dist[node]+trg.second){
                    dist[trg.first] = dist[node]+trg.second;
                    q.push(trg.first);
                }
            }
        }
        
        for(auto x:dist)
            cout << x << " ";
        
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans==INT_MAX?-1:ans;
        
        
        
        
        
        

    }
};