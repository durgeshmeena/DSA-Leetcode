class Solution {
public:
    
    void DFS(int cur, vector<int>& vis, vector<vector<int>>& M){
        vis[cur] = 1;
        for(int j=0; j<M.size(); j++){
            if(M[cur][j] and !vis[j]){
                vis[j] = 1;
                DFS(j, vis, M);
            }
        }
        
    }
    
    
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int>vis(n);
        int prov=0;
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                DFS(i, vis, M);
                prov++;
            }
        }
        
        return prov;
        
        
    }
};