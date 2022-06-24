class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> count;
        int res = 0, sum = 0, i=0;
        
        for(int j=0; j<nums.size(); j++){
            sum += nums[j];
            count[nums[j]]++;
            while(count[nums[j]]!=1){
                count[nums[i]]--;
                sum -= nums[i++];
            }
            res = max(res, sum);
            
        }
        return res;
    }
};