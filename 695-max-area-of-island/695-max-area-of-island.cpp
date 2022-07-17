class Solution {
public:
    int m,n;
    
    int DFS(int i, int j, vector<vector<int>>& B){
        if(i<0 || j<0 || i>=m || j>= n || B[i][j] != 1)
            return 0;
        B[i][j]=0;
        
        return 1 + DFS(i, j-1, B) + DFS(i, j+1, B) + DFS(i-1, j, B) + DFS(i+1, j, B);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& B) {
        m = B.size();
        n = B[0].size();
        
        int res=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j]){
                    res = max(res, DFS(i, j, B));
                }
            }
        
        return res;
        
    }
};