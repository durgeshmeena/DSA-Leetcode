class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int mx=0;
        
        for(auto x:nums){
            mx = mx | x;
        }
        
        return mx;
        
    }
};