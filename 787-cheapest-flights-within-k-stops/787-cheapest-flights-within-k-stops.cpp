class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq;
        vector<int>lastK(n);
        
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        // for(int i=0;i<n;i++){
        //     cout << i << " -> ";
        //     for(auto x:adj[i]){
        //         cout << x.first << " ";
        //     }
        //     cout << "\n";
        // }
            

        pq.push({0,src,k+1});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int cost, node, stop;
            tie(cost, node, stop) = it;
            if(node==dst)
                return cost;
            
            if(stop < lastK[node])continue;
            lastK[node]=stop;
            
            if(stop>0){
                for(auto v:adj[node])
                    pq.push({cost+v.second, v.first, stop-1});
            }
            
            
        }
        
        return -1;
        
        
//         for(auto x:price)
//             cout << x << " ";
//         cout <<"\n";
        
//         return price[dst]==INT_MAX?-1:price[dst];
        
        
    }
};