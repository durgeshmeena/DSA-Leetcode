class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<int> dist(n+1, INT_MAX-100);
        dist[k]=0;
        vector<vector<pair<int, int>>> adj(n+1);
        
        
        for(int i=0; i<n-1; i++){
            
            for(auto edge:times){
                // if(dist[edge[0]] == INT_MAX-100)continue;

                if(dist[edge[1]] > dist[edge[0]] + edge[2]){
                    dist[edge[1]] = dist[edge[0]] + edge[2];
                }
                
            }
            
        }
            
        
        int res = *max_element(dist.begin()+1, dist.end());
        return res != INT_MAX-100 ? res : -1;
        
    }
    
//     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
//         vector<int>dist(n+1, INT_MAX);
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
//         vector<vector<pair<int, int>>> adj(n+1);
//         for(auto v:times){
//             adj[v[0]].push_back({v[1], v[2]});
//         }
        
//         dist[k]=0;
//         pq.push({0, k});
//         while(pq.size()){
//             int prevDist = pq.top().first;
//             int prevNode = pq.top().second;
//             pq.pop();
            
//             for(auto next:adj[prevNode]){
//                 if(dist[next.first] > next.second+dist[prevNode]){
//                     dist[next.first] = next.second+dist[prevNode];
//                     pq.push({dist[next.first], next.first});
//                 }
//             }
            
            
//         }
        
//         int res = *max_element(dist.begin()+1, dist.end());
        
//         return res != INT_MAX ? res : -1;
        
        
        
    
    
//     }
    
};