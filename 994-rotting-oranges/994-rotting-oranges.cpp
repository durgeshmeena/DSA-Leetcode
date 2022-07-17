class Solution {
public:
    int orangesRotting(vector<vector<int>>& M) {
        int r = M.size();
        int c= M[0].size();
        int ocnt = r*c;
        vector<int>dir = {-1,0,1,0,-1};
        queue<vector<int>> q;
        
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                if(M[i][j]==2)
                    q.push({i,j});
                else if(M[i][j]==0)
                    ocnt--;
            }
        
        int step=0;
        int rc, cc, nr, nc;
        while(q.size()){
            int sz = q.size();   
            for(int i=0; i<sz; i++){
                auto v = q.front(); q.pop(); ocnt--;
                rc = v[0]; cc = v[1];
                for(int d=0; d<4; d++){
                    nr = rc+dir[d]; nc = cc+dir[d+1];
                    if(nr>=0 && nc>=0 && nr<r && nc<c && M[nr][nc]==1){
                        M[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            step++;
            
        }
        
        // return step;
        
        return ocnt==0 ?( step ? step-1: step ): -1;
        
    }
};