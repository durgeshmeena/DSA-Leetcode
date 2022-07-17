class Solution {
public:
    int maxDistance(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<vector<int>> q;
        vector<int>dir = {-1,0,1,0,-1};
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(M[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        
        int res = -1;
        int i1,j1, i2,j2;
        
        while(q.size()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                auto v = q.front(); q.pop();
                i1=v[0]; j1=v[1];
                
                for(int d=0; d<4; d++){
                    i2=i1+dir[d]; j2=j1+dir[d+1];
                    if(i2>=0 && j2>=0 && i2<m && j2<n && dist[i2][j2]==INT_MAX){
                        dist[i2][j2] = 1+dist[i1][j1];
                        res = max(res, dist[i2][j2]);
                        q.push({i2,j2});
                    } 
                }
            }
        }
        
        return res;
    }
};