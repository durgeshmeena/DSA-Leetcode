class Solution {
public:
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        // queue<int>q;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto x:times){
           adj[x[0]].push_back({x[1],x[2]}); 
        }
        
     
        dist[k]=0;
        pq.push({0,k});
        
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            
            for(auto trg:adj[node.second]){
                if(dist[trg.first] > node.first+trg.second){
                    dist[trg.first] = node.first+trg.second;
                    pq.push({dist[trg.first], trg.first});
                }
            }
        }
        
        // for(auto x:dist)
        //     cout << x << " ";
        
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans==INT_MAX?-1:ans;
        
        
        
        
        
        

    }
};