class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& M) {
        vector<int> dir = {-1,0,1,0,-1,1,1,-1,-1};
        int m=M.size();
        int n=M[0].size();
        
        if(M[0][0] != 0)return -1;
        M[0][0] = 1;
        
        queue<vector<int>> q;
        q.push({0,0});
        
        int step=1;
        while(q.size()){
            int sz=q.size();
            for(int i=0; i<sz; i++){
                auto v=q.front(); q.pop();
                
                if(v[0]==m-1 && v[1]==n-1)
                    return step;
                
                for(int d=0; d<8; d++){
                    int nr = v[0]+dir[d];
                    int nc = v[1]+dir[d+1];
                    if(nr>=0 && nc>=0 && nr<m && nc<n && M[nr][nc]==0){
                        M[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            step++;
        }
        return -1;
        
    }
};