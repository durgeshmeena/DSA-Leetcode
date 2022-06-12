class Solution {
public:
    
    
    
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int lo=0, hi=n-1;
        int mid;
        
        while(lo < hi) {
            mid = lo + (hi-lo)/2;
            if(arr[mid]<arr[mid+1])
                lo = mid+1;
            else
                hi = mid;
        }
        return lo;
        
        
        
    }    
    
    // bool isValid(int i, vector<int>& arr, int n){ 
    //     if( arr[i]>arr[i+1] and arr[i]>arr[i-1] ) return true;
    //     return false;
    // }
    
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int n = arr.size();
//         int lo=1, hi=n-2;
//         int mid;
        
//         if(arr[0]>arr[1])return 0;
//         else if (arr[n-1] > arr[n-2])return n-1;
        
//         while(lo < hi) {
//             mid = lo + (hi-lo)/2;
            
//             if(isValid(mid, arr,n))
//                 return mid;
//             else if(arr[mid]>arr[mid+1])
//                 hi = mid;
//             else if(arr[mid-1]<arr[mid])
//                 lo = mid+1;
//         }
        
//         return lo;
        
//     }
};