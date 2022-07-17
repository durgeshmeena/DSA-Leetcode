class Solution {
public:
    int m,n;
    
    
    int DFS(int i, int j, vector<vector<int>>& B){
        if(i<0 || j<0 || i>=m || j>= n || B[i][j] != 1)
            return 0;
        B[i][j]=0;
        
        return 1 + DFS(i, j-1, B) + DFS(i, j+1, B) + DFS(i-1, j, B) + DFS(i+1, j, B);
    }
    
    vector<int> dir = {-1,0,1,0,-1};
    
    int DFS_stack(int i, int j, vector<vector<int>>& B){
        int res=0;
        stack<vector<int>> st;
        st.push({i,j});
        B[i][j]=0;
        while(st.size()){
            auto v = st.top(); st.pop();
            res++;
            for(int d=0; d<4; d++){
                int i2 = v[0]+dir[d];
                int j2 = v[1]+dir[d+1];
                if(!(i2<0 || j2<0 || i2>=m || j2>= n || B[i2][j2] != 1)){
                    B[i2][j2] = 0;
                    st.push({i2,j2});
                }
            }
            
        }
        return res;
    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& B) {
        m = B.size();
        n = B[0].size();
        
        int res=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(B[i][j]){
                    res = max(res, DFS_stack(i, j, B));
                }
            }
        
        return res;
        
    }
};