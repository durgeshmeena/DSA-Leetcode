class Solution {
public:
    int row,col;
    void dfs(int i, int j, vector<vector<char>>& B){
        if(i<0 or j<0 or i>=row or j >=col or B[i][j]!='O')
            return;
        B[i][j]='C';
        
        dfs(i,j-1,B), dfs(i,j+1,B);
        dfs(i-1,j,B), dfs(i+1,j,B);
        
    }
    
    void solve(vector<vector<char>>& B) {
        row=B.size();
        col=B[0].size();
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(i==0 or j==0 or i==row-1 or j==col-1)
                    if(B[i][j]=='O')
                        dfs(i,j,B);
            }
        
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(B[i][j]=='O')B[i][j]='X';
                else if(B[i][j]=='C')B[i][j]='O';                 
            }
        
        
    }
};