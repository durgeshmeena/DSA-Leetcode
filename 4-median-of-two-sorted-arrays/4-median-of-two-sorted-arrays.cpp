class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        if(n1 > n2)
            return findMedianSortedArrays(arr2, arr1);
        
        
        if(n1==0){
            if(n2%2!=0)
                return arr2[n2/2];
            return (arr2[-1+n2/2]+arr2[n2/2])/2.0;
        }
        
        int k = (n1+n2)/2;
        
        
        int lo = 0, hi = n1-1;        
        
        while(lo < hi) {
        
            int mid1 = lo+(hi-lo)/2;
            int mid2 = k-mid1-2;
            
            if(arr1[mid1] < arr2[mid2+1])
                lo = mid1+1;
            else
                hi = mid1;
            
        }
        
        int i=lo;
        int j=k-lo-2;
        
        int arr1_l=arr1[i], arr1_r, arr2_l, arr2_r=arr2[j+1];
        
        if(arr1_l >= arr2_r){
            i--;
            j++;
        }
        
        arr1_l = i>=0?arr1[i]:-INT_MAX;
        arr2_r = (j+1)<n2?arr2[j+1]:INT_MAX;
          
        arr1_r = (i+1)<n1?arr1[i+1]:INT_MAX;
        arr2_l = j>=0?arr2[j]:-INT_MAX;
        
        
        
  
            
        if((n1+n2)%2!=0)
            return min(arr1_r, arr2_r);

        return (max(arr1_l, arr2_l)+min(arr1_r, arr2_r))/2.0;

        
        
        
        
        return -1.0;
        
        
        
        
        
    }
};