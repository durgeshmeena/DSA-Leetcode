class Solution {
public:
    int m,n;
    
    vector<int>dir = {-1, 0, 1, 0, -1};
    
    void DFS(int i, int j, vector<vector<char>>& B){
        if(i<0 || j<0 || i>=m || j>= n || B[i][j] != '1')
            return;
        B[i][j] = '0';
        
        DFS(i-1, j, B); DFS(i+1, j, B);
        DFS(i, j-1, B); DFS(i, j+1, B);
        
    }
    
    
    void BFS(int i, int j, vector<vector<char>>& B){
        queue<vector<int>>q;
        q.push({i,j});
        B[i][j] = '0';
        
        while(!q.empty()){
            int sz = q.size();
            for(int k=0; k<sz; k++){
                auto node = q.front(); q.pop();
                int i1 = node[0];
                int j1 = node[1];
                
                // result
                
                for(int d=0; d<4; d++){
                    int i2 = i1 + dir[d];
                    int j2 = j1 + dir[d+1];
                    
                    if(i2<0 || j2 <0 || i2 >= m || j2 >= n || B[i2][j2]!= '1' ){
                        // skip
                    }
                    else{
                        B[i2][j2] = '0';
                        q.push({i2, j2});
                    }
                        
                }
                
                
            }
        }
        
    }
    
    
    
    int numIslands(vector<vector<char>>& B) {
        m = B.size();
        n = B[0].size();
        
        int res=0;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j] == '1'){
                    BFS(i, j, B);
                    res++;
                }
            }
        return res;
    }
};