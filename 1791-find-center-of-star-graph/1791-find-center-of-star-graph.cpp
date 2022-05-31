class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>>ad(edges.size()+2);

        for(int i=0; i<edges.size(); i++){
            ad[edges[i][0]].push_back(edges[i][1]);
            ad[edges[i][1]].push_back(edges[i][0]);
        }
        
        int c=0,s=1;
        for(int i=1; i<=ad.size(); i++){
            if(ad[i].size() > s){
                c=i;
                break;
            }
        }
        
        return c;
        
    }
};