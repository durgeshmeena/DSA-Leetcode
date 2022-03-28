class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int count;
        int flag = 1;
        if (nums[nums.size()-1] == 0)count=0;
        for (int i=nums.size()-2; i>=0; i--) {
            
            if (flag) {
                if (nums[i] > 0)continue;
                flag = 0;
                count = 1;
            }
            else {
                if (nums[i] > count){
                    flag = 1;
                    
                }
                count++;
                
                
            }
        }
        
        return flag;
    }
};