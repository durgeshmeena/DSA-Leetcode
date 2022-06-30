class Solution {
public:
    int m,n;
    int cnt = 0;
    
    void BFS(int i, int j, vector<vector<char>>& B){
        vector<int>dir = {0,-1,0,1,0};
        queue< vector<int> > q;
        q.push({i,j});
        
        while(!q.empty()){
            int sz = q.size();
            for(int s=0; s<sz; s++){
                vector<int>v = q.front();
                int i1 = v[0], j1 = v[1];
                B[i1][j1] = '0';
                q.pop();
                for(int k=0; k<4; k++){
                    int i2 = i1+dir[k], j2 = j1+dir[k+1];
                    if(!(i2<0 || j2<0 || i2>=m || j2>=n || B[i2][j2]=='0')){
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

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j]=='1'){
                    cnt++;
                    BFS(i,j, B);
                }
            }
        
        return cnt;
        
        
    }
};