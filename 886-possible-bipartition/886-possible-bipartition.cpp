class Solution {
public:
    vector<int>parent;
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(n+1);
        vector<vector<int>>adj(n+1);
        
        for(int i=0;i<=n;i++)
            parent[i]=i;
        
        for(auto x:dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        
        
        for(int i=1;i<=n;i++)
            for(int j=0; j<adj[i].size(); j++){
                if(find(i)==find(adj[i][j]))
                    return false;
                if(adj[i].size()>0)
                    uni(adj[i][0], adj[i][j]);
            }
            
        
        return true;
    
    }
    
    
    int find(int x){
        if(parent[x]==x)
            return x;
        else
            return parent[x]=find(parent[x]);
    }
    
    void uni(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b) parent[b]=a;
    }
};