class Solution {
public:
    int m,n;
    
    void DFS(int i, int j, vector<vector<char>>& B){
        if(i<0 || j<0 || i>=m || j>= n || B[i][j] != '1')
            return;
        B[i][j] = '0';
        
        DFS(i-1, j, B); DFS(i+1, j, B);
        DFS(i, j-1, B); DFS(i, j+1, B);
        
    }
    
    int numIslands(vector<vector<char>>& B) {
        m = B.size();
        n = B[0].size();
        
        int res=0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j] == '1'){
                    DFS(i, j, B);
                    res++;
                }
            }
        return res;
    }
};