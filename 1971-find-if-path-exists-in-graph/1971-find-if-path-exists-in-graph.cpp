class Solution {
public:
    
    
    
    void DFS(int node, int g, vector<int>& group, vector<vector<int>>& ad){
        group[node] = g;
        
        for(auto it:ad[node]){
            if(group[it]==-1){
                DFS(it, g, group, ad);
            }
        }
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>group(n, -1);
        vector<vector<int>>ad(n);
        
        for(int i=0; i<edges.size(); i++){
            ad[edges[i][0]].push_back(edges[i][1]);
            ad[edges[i][1]].push_back(edges[i][0]);

        }
        
        
        for(int i=0; i<n; i++){
            if(group[i]==-1){
                DFS(i, i, group, ad);
            }
        }
        
        return group[source] == group[destination];
        
    }
};