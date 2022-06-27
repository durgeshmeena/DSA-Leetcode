class Solution {
public:
    vector<int> getRow(int row) {
        if(row==0)
            return {1};
        
        vector<int>v = getRow(row-1);
        
        for(int i=v.size()-1; i>0; i--){
            v[i] = v[i]+v[i-1];
        }
        v.push_back(1);
        
        return v;
        
        
        
    }
};