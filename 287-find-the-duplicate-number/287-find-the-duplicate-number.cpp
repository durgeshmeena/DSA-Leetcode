class Solution {
public:
    
    // bool cnd(int x, vector<int>& nums) {
    //     int cnt=0;
    //     for(auto num:nums){
    //         if(num<=x)
    //             cnt++;
    //     }
    //     if(cnt>x)
    //         return true;
    //     return false;
    // }
    
    int findDuplicate(vector<int>& nums) {
        int lo=1, hi=nums.size()-1;
        
    
        auto cnd = [&](int x){
            int cnt=0;
            for(auto num:nums){
                if(num<=x)
                    cnt++;
            }
            if(cnt>x)
                return true;
            return false;         
        };
        
        
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            
            cout << lo << " " << hi << " -" << mid << "\n";
            
            if(cnd(mid)==false)
                lo = mid+1;
            else
                hi=mid;
        }
        
        return lo;

    }
};