class Solution {
public:
    
    void dfs(int i, vector<int>&vis, vector<vector<int>>&M){
        vis[i] = 1;
        for(int j = 0; j < vis.size(); j++){
            if(!vis[j] and i!=j and M[i][j])
                dfs(j, vis, M);
         }
    }
    
    int findCircleNum(vector<vector<int>>&M) {
        int n = M.size();
        vector<int>vis(n);
        int prov=0;
        for(int i=0; i<n; i++){
                if(!vis[i]){
                    dfs(i, vis, M);
                    prov++;
                }
        }
        return prov;
    }
};