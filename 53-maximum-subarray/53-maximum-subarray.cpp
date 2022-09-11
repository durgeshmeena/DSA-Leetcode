class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        
        int maxi=INT_MIN;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            cur+=nums[i];
            maxi=max(cur,maxi);
           if(cur<0)cur=0;
            
            
        }
        return maxi;
    }
};