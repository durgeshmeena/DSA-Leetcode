class Solution {
public:
    
    
    void pascal(int r, vector<int>&v){
        if(r<0)
            return;
        
        pascal(r-1, v);
        
        for(int i=v.size()-1; i>0; i--){
            v[i] = v[i]+v[i-1];
        }
        v.push_back(1);
        
    }
    
    
    vector<int> getRow(int row) {
//         if(row==0)
//             return {1};
        
//         vector<int>v = getRow(row-1);
        
//         for(int i=v.size()-1; i>0; i--){
//             v[i] = v[i]+v[i-1];
//         }
//         v.push_back(1);
        
//         return v;
        
        
        vector<int>v;
        
        pascal(row, v);
        
        return v;
        
        
        
    }
};