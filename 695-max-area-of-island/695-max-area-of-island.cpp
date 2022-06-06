class Solution {
public:
    int row,col;
    
    int dfs(int i, int j, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]==0)
            return 0;
        
        grid[i][j]=0;
        
        int j1 = dfs(i,j-1,grid);
        int j2 = dfs(i,j+1,grid);
        int i1 = dfs(i-1,j,grid);
        int i2 = dfs(i+1,j,grid);
        
        return 1+i1+i2+j1+j2;
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        
        int island=0;
        
        for(int i=0; i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]==1){
                    island = max(island, dfs(i,j,grid));
                }
                    
        return island;
    }
    
};