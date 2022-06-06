class Solution {
public:
    int row,col;
    
    void dfs(int i, int j, vector<vector<int>>& A) {
        if(i<0 || j<0 || i>=row || j>=col || A[i][j]!=0)
            return;
        
        A[i][j]=1;
        
        dfs(i,j-1,A),dfs(i,j+1,A);
        dfs(i-1,j,A),dfs(i+1,j,A);
       

    }
        
    int closedIsland(vector<vector<int>>& A) {
        row = A.size();
        col = A[0].size();
        
        int island=0;
        
        for(int i=0;i<row;i++)
            for(int j=0; j<col;j++){
                if(i==0 || j==0 || i==row-1 || j==col-1)
                    if(A[i][j]==0)
                        dfs(i,j,A);
            }
        
        for(int i=1;i<row-1;i++)
            for(int j=1; j<col-1;j++){
                if(A[i][j]==0){
                    dfs(i,j,A);
                    island++;
                }
                    
            }
        
        return island;
        
    }
};