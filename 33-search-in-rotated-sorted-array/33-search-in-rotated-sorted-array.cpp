class Solution {
public:
    int search(vector<int>& arr, int trgt) {
        
        int lo=0, hi=arr.size()-1;
        
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid]>arr[hi])
                lo = mid+1;
            else
                hi=mid;
        }
        int ind = lo;
        
        cout << "low = "<< ind << "\n";
        
        
        auto bs = [&](int lo, int hi){
             while(lo < hi) {
                int mid = lo + (hi-lo)/2;

                if(arr[mid] < trgt)
                    lo = mid+1;
                else
                    hi=mid;
            } 
            return arr[lo]==trgt?lo:-1;           
        };
        
        
        int ans1 = bs(0,ind-1);
        
        if(ans1!=-1)
            return ans1;
        
        int ans2 = bs(ind, arr.size()-1);
        if(ans2!=-1)
            return ans2;
        
        return -1;
    
        
        
    }
};