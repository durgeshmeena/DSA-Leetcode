class Solution {
public:
    
    vector<int>safe;
    
    int DFS(int i, vector<int>& color, vector<vector<int>>& adj){
        if(adj[i].size()==0)
            return color[i] = 2;
        
        color[i] = 1;
        
        for(auto next:adj[i]){
            if(color[next]==0 && DFS(next, color, adj)==1 ){
                return color[i]=1;
            }
            else if(color[next]==1)
                return color[i]=1;
        }
        
        return color[i]=2;
    }
    
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        
        for(int i=0; i<n; i++){
            if(color[i]==0){
                if(DFS(i, color, graph)==2)
                    safe.push_back(i);
            }
            else{
                if(color[i]==2)
                    safe.push_back(i);
            }
            
             
                        
        }
        
        return safe;
    }
};