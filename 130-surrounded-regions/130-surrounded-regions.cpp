class Solution {
public:
    int m,n;
    
    void DFS(int i, int j, vector<vector<char>>& B){
        if(i<0 || i>=m || j<0 || j>=n || B[i][j]!='O')
            return;
        
        B[i][j] = '#';
        
        DFS(i-1, j, B); DFS(i+1, j, B);
        DFS(i, j-1, B); DFS(i, j+1, B);
        
    }
    
    void solve(vector<vector<char>>& B) {
        m = B.size();
        n = B[0].size();
        
        for(int i=0; i<B.size(); i++)
            for(int j=0; j<B[0].size(); j++){
                if(i==0 || j==0 || i==m-1 || j==n-1){
                    if(B[i][j]=='O')
                        DFS(i,j, B);
                }
            }
        
        
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j]=='O')
                    B[i][j]='X';
                
                else if(B[i][j]=='#')
                    B[i][j]='O';
            }
        
        
    }
};