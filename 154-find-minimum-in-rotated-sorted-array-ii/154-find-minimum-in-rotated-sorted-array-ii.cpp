class Solution {
public:
    int findMin(vector<int>& arr) {
        int lo=0, hi=arr.size()-1;
        
        while(lo < hi) {
            
            if(arr[lo]==arr[hi]){
                lo = lo+1;
                continue;
            }
            
            int mid = lo + (hi-lo)/2;
            if(arr[mid]>arr[hi])
                lo = mid+1;
            else
                hi=mid;
        }
        int ind = lo;
        
        cout << "low = "<< ind << "\n";   
        return arr[lo];
    }
};