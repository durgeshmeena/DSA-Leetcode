class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int l = 0, r = n-1;
        while(l<r){
            
            for(auto x:nums)
                cout << x << " ";
            cout <<"\n";
            
            if(nums[l]==2 or nums[r]==0){
                swap(nums[l], nums[r]);
                if(  nums[l]==0?(l++,(nums[r]==2)?r--,true:true ):(r--, true) ) continue;
            }
            
            else{
                l++;
            }
            
            
        }
        cout <<"\n";
        l = 0, r = n-1;
        while(l<r){
            
            for(auto x:nums)
                cout << x << " ";
            cout <<"\n";
            
            if(nums[r]==2){r--; continue;}
            
            if(nums[l]==1 or nums[r]==0){
                swap(nums[l], nums[r]);
                if(  nums[l]==0?(l++,(nums[r]==1)?r--,true:true ):(r--, true) ) continue;
            }
            
            else{
                r--;
            }
            
            
        }      
        
    }
};