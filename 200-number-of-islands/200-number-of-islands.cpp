class Solution {
public:
    int row,col;
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]=='0')
            return;
        grid[i][j]='0';
        
        dfs(i,j-1,grid),dfs(i,j+1,grid);
        dfs(i-1,j,grid),dfs(i+1,j,grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        row=grid.size();
        col=grid[0].size();
        int island=0;
        
        for(int i=0; i<row;i++)
            for(int j=0;j<col;j++)
                if(grid[i][j]=='1')
                    dfs(i,j,grid),island++;
        return island;
    }
    
};