class Solution {
public:
    vector<int>parent;
    int n;
    void unionN(int u, int v){
        int uP = findPar(u);
        int vP = findPar(v);
        
        if(uP!=vP){
            parent[vP] = uP;
        }
        
    }
    
    int findPar(int u){
        if(parent[u] == u)
            return u;
        return parent[u] = findPar(parent[u]);
    }
    
    int findCircleNum(vector<vector<int>>& M) {
        this->n = M.size();
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;

        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++){
                if(M[i][j])
                    unionN(i,j);
            }
        
    
        int prov=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i)
                prov++;
        }
        return prov;
        
        
        
        
    }
};



// class Solution {
// public:
//     int parent[201];
    
//     int findCircleNum(vector<vector<int>>& M) {
//         int i, j, groups = 0, n = M.size();
        
//         for(int i = 0; i < n; i++) 
//             parent[i] = i;
          
//         for(i = 0; i < n; i++) {
//             for(j = i + 1; j < n; j++) {
//                 if(M[i][j])
//                     union_sets(i, j);
//             }
//         }
        
//         for(i = 0; i < n; i++) {
//             if(i == parent[i])
//                 groups++;
//         }
        
//         return groups;
//     }

// private:

//     int find_set(int v) {
//         if (v == parent[v])
//             return v;
//         return parent[v] = find_set(parent[v]);
//     }
    
//     void union_sets(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if (a != b)
//             parent[b] = a;
//     }
// };