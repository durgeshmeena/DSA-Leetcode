class Solution {
public:
    int maxDistance(vector<vector<int>>& M) {
        int r=M.size(), c=M[0].size();
        vector<vector<int>>dist(r, vector<int>(c,-1));
        queue<pair<int,int>>q;
        int MX_Dist=-1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(M[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        vector<int>dir({-1,0,1,0,-1});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i,j;
            i = it.first, j = it.second;
            
            for(int k=0;k<4;k++){
                int ni,nj;
                ni = i + dir[k];
                nj = j + dir[k+1];
                
                if(ni<0 || nj<0 || ni>=r || nj>=c || dist[ni][nj]!=-1)continue;
                else {
                    dist[ni][nj] = dist[i][j]+1;
                    q.push({ni,nj});
                    
                    MX_Dist = max(MX_Dist, dist[ni][nj]);
                }
            }
            
            
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout << dist[i][j] << " ";
            }
            cout << "\n";
        }        
        
        
        return MX_Dist;
        
        
    }
};