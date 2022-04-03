class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int ki = n-1;
        int kj = 0;
        int flag = 1;
        int last = INT_MAX;
        
        for (int i=n-2; i>=0; i--) {
            for (int j=i+1; j<=n-1;j++) {
                if (nums[j] > nums[i]) {
                    ki=i;
                    if (nums[j] < last)kj=j;
                    last = nums[j];
                    flag=0;
                }
            }
            if (flag == 0)break;
            
        }
        
        int tmp = nums[ki];
        nums[ki] = nums[kj];
        nums[kj] = tmp;
    
        if (flag == 1)ki=-1;
        sort(nums.begin()+ki+1, nums.end());
        
    }
};