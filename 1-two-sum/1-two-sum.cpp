class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0, j=n-1;
        multimap<int, int>ind;
        for(int i=0; i<n; i++){
            ind.insert({nums[i],i});
        }
        int a,b;
        sort(nums.begin(), nums.end());
        while(i<j) {
            
            int sum = nums[i]+nums[j];
            if(sum==target){a=nums[i];b=nums[j];break;}
                
            else if(sum>target)
                j--;
            else
                i++;
        }
        
        vector<int>v;
        
        for(auto it=ind.begin(); it!=ind.end(); it++){
            int val = it->first;
            int i = it->second;
            if(val==a)
                v.push_back(i);
            else if(val==b)
                v.push_back(i);
        }
        
        return v;
        
            
    }
};