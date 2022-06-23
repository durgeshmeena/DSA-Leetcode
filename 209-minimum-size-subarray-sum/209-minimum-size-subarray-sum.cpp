class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0, len=INT_MAX, n=nums.size();
        
        int i=0;
        for(int j=0; j<n; j++) {
            sum+=nums[j];
            
            while(sum>=target){
                len = min(len, j-i+1);
                sum -= nums[i++];
                
            }
            
                
            cout << sum << " ";
            
        }
        
        return len==INT_MAX?0:len;
        
    }
};