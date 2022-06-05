class Solution {
public:
    
    int parent[1000];
    int rank[1000];
    int n;
    
    int findP(int index){
        if(parent[index]==index) return index;   
        return parent[index] = findP(parent[index]);
    }
    
    void combine(int ind1, vector<int>u, int ind2, vector<int>v){
        int u1 = findP(ind1);
        int v1 = findP(ind2);

        if(u1!=v1){
                if(rank[u1] > rank[v1])
                    parent[v1] = u1;   
                else if(rank[u1] < rank[v1])
                    parent[u1] = v1;
                else{
                    parent[v1] = u1;
                    rank[u1]++;
                }
            
        }
    }
    
    
    
    
    int removeStones(vector<vector<int>>& stones) {
        this->n = stones.size();
        
        for(int i=0;i<n; i++)
            parent[i]=i,rank[i]=0;
        
        for(int i=0;i<n;i++){
            for(int j=0; j<n; j++){
                if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
                    combine(i,stones[i], j,stones[j]);
                }
            }
                
            
            // for(int i=0; i<n; i++)
            //     cout << parent[i] << " ";
            // cout <<"\n";
        }
            

        int cnt=0;
        for(int i=0; i<n; i++){
            if(parent[i]==i)cnt++;
        }
        
        return n-cnt;
    }
    
    
};