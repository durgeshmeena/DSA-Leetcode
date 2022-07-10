class Solution {
public:
    
    vector<vector<int>>ans;
    int n, k;
    
    void cominations(int i, vector<int>v){
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        
        if(i>n)
            return;
        if(i <= n+v.size()-k)
            cominations(i+1, v);
        v.push_back(i);
        cominations(i+1, v);
            
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        this->n = n;
        this->k = k;
        
        cominations(1, v);
        return ans;
    }
};