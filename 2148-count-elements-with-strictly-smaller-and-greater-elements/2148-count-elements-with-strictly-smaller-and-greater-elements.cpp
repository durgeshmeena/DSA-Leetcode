class Solution {
public:
    int countElements(vector<int>& nums) {
        int N=nums.size();
        if(N<3)
            return 0;
        
        sort(nums.begin(), nums.end());
        
        int lo=0,hi=nums.size()-1,mid;
        int target = nums[0];

        while(lo < hi) {
            mid = lo+(hi-lo)/2;
            
            if(nums[mid]>target)
                hi=mid;
            else
                lo=mid+1; 
        }
        int lower_bound = lo;
        
        // if(lo==N-1)
        //     return 0;
        
        lo=0,hi=N-1;
        target = nums[N-1];

        while(lo < hi) {
            mid = lo+(hi-lo+1)/2;
            
            if(nums[mid] < target)
                lo=mid;
            else
                hi=mid-1; 
        } 
        
        int upper_bound = lo;
        int ans = upper_bound - lower_bound + 1;
        return ans>0?ans:0;
        
        
            
    }
};