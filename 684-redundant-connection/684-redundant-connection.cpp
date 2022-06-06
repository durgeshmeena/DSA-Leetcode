class Solution {
public:
    int parent[1001];
    int rank[1001];
    
    int find(int u){
        if(parent[u]==u)
            return u;
        return parent[u] = find(parent[u]);
    }
    
    void uni(int u, int v){
        int up = find(u);
        int vp = find(v);
        if(up!=vp){
            int rUP=rank[up];
            int rVP=rank[vp];
            if(rUP>rVP)
                parent[vp]=up;
            else if(rVP>rUP)
                parent[up]=vp;
            else{
                parent[vp]=up;
                rank[up]++;    
            }
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans(2);
        int n = edges.size();
        for(int i=1;i<=n;i++)
            parent[i]=i,rank[i]=0;
        
        for(int i=0;i<n;i++){
            int x = find(edges[i][0]);
            int y = find(edges[i][1]);
            if(x==y)
                ans = {edges[i][0],edges[i][1]};
            uni(edges[i][0],edges[i][1]);
        }
        
        
        return ans;
        
        
    }
};