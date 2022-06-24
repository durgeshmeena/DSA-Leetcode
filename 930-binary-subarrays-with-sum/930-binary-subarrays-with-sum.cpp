class Solution {
public:
    
    int atMost(vector<int>& arr, int k){
        if(k<0)
            return 0;
        int oneCount=0, i=0, res=0;
        int n = arr.size();
        for(int j=0; j<n; j++){
            if(arr[j]==1)
                oneCount++;
            while(oneCount>k){
                if(arr[i]==1)oneCount--;
                i++;
            }
            res += (j-i+1);
        }
        return res;
        
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal)-atMost(nums, goal-1);
    }
};