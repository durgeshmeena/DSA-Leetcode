class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char x) {
        int lo=0,hi=arr.size()-1;
        int mid,N=arr.size();
        while(lo<=hi) {
            mid = lo+(hi-lo)/2;
            if(arr[mid]==x)
                lo = (mid+1);
            else if(arr[mid]>x)
                hi = mid-1;
            else if(arr[mid]<x)
                lo = mid+1;
            
        }
        cout << lo << "\n";
        return arr[lo%N];
       
        
    }
};