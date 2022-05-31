class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> point(n+1, vector<int>(2,0));        
        for(auto t:trust){
            point[t[1]][0]++;
            point[t[0]][1] = t[1];
        }
        
        for(int i=1; i<=n; i++){
            if(point[i][0]==n-1 and point[i][1]==0)
                return i;
        }     
                                  
        return -1; 
    }
                                  
};