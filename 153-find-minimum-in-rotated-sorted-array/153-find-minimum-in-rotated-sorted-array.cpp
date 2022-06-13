class Solution {
public:
    int findMin(vector<int>& arr) {
        
        
        
        
        
        
        
        
        
        
        
        int lo=0, hi=arr.size()-1;
        
        while(lo < hi) {
            int mid = lo + (hi-lo)/2;
            
            if(arr[mid] > arr[hi])
                lo = mid+1;
            else
                hi = mid;
                
                
        }
        
        return arr[lo];
        
    }
};