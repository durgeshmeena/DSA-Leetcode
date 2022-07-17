class Solution {
public:
    int m,n;
    
    void DFS(int i, int j, int val, int color, vector<vector<int>>& B){
        if(i<0 || j<0 || i>=m || j>=n || B[i][j]==color || B[i][j] != val)
            return;
        B[i][j] = color;
        
        DFS(i,j-1,val,color,B); DFS(i,j+1,val,color,B);
        DFS(i-1,j,val,color,B); DFS(i+1,j,val,color,B);
    }
    
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& B, int sr, int sc, int color) {
        m = B.size();
        n = B[0].size();
        
        DFS(sr, sc, B[sr][sc], color, B);
        
        return B;
    }
};