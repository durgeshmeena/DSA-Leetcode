class Solution {
public:
    int m,n;
    
    void DFS(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != 1)
            return;
        
        grid[i][j] = 0;
        
        DFS(i-1, j, grid); DFS(i+1, j, grid);
        DFS(i, j-1, grid); DFS(i, j+1, grid);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(grid[i][j]) DFS(i, j, grid);
                }
            }
        
        
        int cnt=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                cnt += grid[i][j];
            }
        
        return cnt;
        
    }
};