class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<pair<int,int>>adj[n];
        
        for(auto v:edges){
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        auto bfs = [&](int src){
            
            vector<int> dist(n, INT_MAX);
            dist[src]=0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, src});
            
            while(pq.size()){
                auto ddist = pq.top().first;
                auto nnode = pq.top().second;
                pq.pop();
                
                for(auto x:adj[nnode]){
                    if(dist[x.first] > ddist+x.second){
                        dist[x.first] = ddist+x.second;
                        pq.push({dist[x.first], x.first});
                    }
                }
                
            }
            
            int count=-1;
            for(int i=0; i<n; i++){
                if(dist[i] <= distanceThreshold)count++;
            }
            
            return count;
            
        };
        
        int dist = INT_MAX, node=-1;
        for(int i=0; i<n; i++){
            int ndist = bfs(i);
            if(ndist <= dist){
                dist = ndist;
                node = i;
            }
        }
        
        return node;
        
    }
};