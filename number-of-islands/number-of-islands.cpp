class Solution {
public:
    
    int island = 0, m, n;
    vector<int> dir = {-1,0,1,0,-1};
    
    void DFS(int i, int j, vector<vector<char>>& B){
        if(i<0 || j<0 || i>=m || j>= n || B[i][j]=='0')
            return;
        
        B[i][j]='0';
        
        for(int k=0; k<4; k++){
            DFS(i+dir[k], j+dir[k+1], B);
        }
    }
    
    int numIslands(vector<vector<char>>& B) {
        m = B.size();
        n = B[0].size();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j]=='1'){
                    island++;
                    DFS(i,j, B);
                }
            }
        
        
        return island;
        
    }
};