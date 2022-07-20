class Solution {
public:
    int r,c;
    vector<int> dir = {0,1,0,-1,0};
    
    void print(vector<vector<int>>& A){
        cout << endl;
        for(int i=0; i<A.size(); i++){
            for(int j=0; j<A[0].size(); j++){
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    bool dfs(int i,int j,int ind,vector<vector<int>>&vis,vector<vector<char>>&B,string& w){
        if(B[i][j]!=w[ind])return false;
        vis[i][j]=1;
        if(ind==w.size()-1)return true;
        // print(vis);
          
        for(int d=0; d<4; d++){
            int ni = i+dir[d];
            int nj = j+dir[d+1];
            if(ni>=0 && nj>=0 && ni<r && nj<c && !vis[ni][nj]){
                if(dfs(ni,nj,ind+1,vis,B,w))
                    return true;
            }
        }
        
        vis[i][j]=0;
        // cout << "\n";
        return false;
        
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();
        
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                    vector<vector<int>> vis(r, vector<int>(c));
                    if(dfs(i, j, 0, vis, board, word))
                        return true;
            
            }
        
        return false;
        
    }
};