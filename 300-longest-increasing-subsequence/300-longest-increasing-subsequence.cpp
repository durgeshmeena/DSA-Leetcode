class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr({nums[0]});
        
        for(int i=1; i<n; i++){
            if(nums[i]>arr[arr.size()-1])
                arr.push_back(nums[i]);
            else{
                auto it = lower_bound(arr.begin(), arr.end(), nums[i]);
                *it = nums[i];
            }
        }
        
        return arr.size();
        
    }
};