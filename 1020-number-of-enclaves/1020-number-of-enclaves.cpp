class Solution {
public:
    int m,n;
    void dfs(int i, int j, vector<vector<int>>& A){
        if(i<0 or j<0 or i>=m or j>=n)return;
        if(A[i][j]!=1)return;
        
        A[i][j]=-1;
        
        dfs(i,j-1,A);
        dfs(i,j+1,A);
        dfs(i-1,j,A);
        dfs(i+1,j,A);
        
        
    }
    
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size();
        n = A[0].size();
           
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(i==0 or j==0 or i==m-1 or j==n-1)
                    if(A[i][j]==1)
                        dfs(i,j, A);
            }
       
        int ans=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                    if(A[i][j]==1)
                        ans++;
            }        
        
        return ans;
    }
};