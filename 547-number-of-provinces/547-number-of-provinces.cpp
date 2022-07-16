class Solution {
public:
    int province;
    
    int Find(int a, vector<int>& parent){
        int aP = parent[a];
        if(a == aP)
            return a;
        return parent[a] = Find(aP, parent);
    }
    
    void Union(int a, int b, vector<int>& parent){
        int aP = Find(a, parent);
        int bP = Find(b, parent);
        
        if(aP != bP){
            parent[bP] = aP;
            province--;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>parent(n+1);
        province = n;
        for(int i=1; i<=n; i++)
            parent[i]=i;
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j]) 
                    Union(i, j, parent);
            }
        
        return province;
    }
};