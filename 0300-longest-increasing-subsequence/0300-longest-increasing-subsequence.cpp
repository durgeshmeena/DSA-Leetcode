class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int>v={nums[0]};
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>(v[v.size()-1]))
                v.push_back(nums[i]);
            else {
                auto it=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
                v[it]=nums[i];
            }
        }
        return v.size();
    }
};