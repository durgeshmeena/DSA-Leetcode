class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        long long sum = 0;
        int f_ele = nums[0];
        if (f_ele-1 <= k ) {
            long long i_sum = (long long)f_ele*(f_ele-1)/2;
            k -= f_ele-1;
            sum += i_sum;
        }
        else {
            long long i_sum = (long long)k*(k+1)/2;
            sum += i_sum;
            k = 0;
        }
       
        
        int s = nums.size();
        int i=1, j=f_ele+1;
        
        while (k>0 and i<s) {
            if (nums[i]>j) {
                sum += j;
                j++;
                k--;
            } 
            else if (nums[i] == j) {
                i++;
                j++;
            }
            else if (nums[i]<j) i++;
        }
        
        
        
        if (k) {
            long long r_sum = (long long)(nums[s-1]+k)*(nums[s-1]+k+1)/2;
            long long l_sum = (long long)(nums[s-1])*(nums[s-1]+1)/2;

            sum += r_sum - l_sum;           
        }
        
        return sum;
        
        
        
        
        
        
        

        
    }
};