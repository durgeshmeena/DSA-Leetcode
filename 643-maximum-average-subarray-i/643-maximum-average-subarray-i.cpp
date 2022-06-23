class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double f = 1.0/k, avg=INT_MIN,sum=0;
        int i=0, n = nums.size();
        
        for(int j=0; j<n; j++){
            sum+=nums[j];
            if(j-i+1<k){
                continue;
            }
            else if(j-i+1==k) {
                avg = max(avg, f*sum);
                sum -= nums[i];
                i++;
                    
            }
            
        }
        return avg;
    }
};