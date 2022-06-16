class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>v(nums.size());
        int l=0, r=nums.size()-1;
        int curr = r;
        
        while(l<=r) {
            if( abs(nums[l])<abs(nums[r]) ) {
                v[curr] = nums[r]*nums[r], r--;
            }
                
            else
                v[curr] = nums[l]*nums[l], l++;
            
            curr--;
        }
        
        return v;
        
    }
};