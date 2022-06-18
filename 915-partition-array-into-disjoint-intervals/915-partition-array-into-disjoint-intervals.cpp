class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int>mini(n);
        vector<int>maxi(n);
        
        int mn=nums[n-1], mx = nums[0];
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            mx = max(nums[i], mx);
            maxi[i] = mx;
            
            mn = min(nums[n-1-i], mn);
            mini[n-1-i] = mn;
            
        
            
        }
        int i=0;
        while(i<n-1){
            if(maxi[i]<=mini[i+1])
                return i+1;
            i++;
        }
        
        return ans;
        
        
        
        
    }
};