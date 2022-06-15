class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        if(n1>n2)
            return findMedianSortedArrays(arr2, arr1);
        
        int k = (n1+n2)/2;
        int l=0, r=n1-1;
        int arr1_l, arr1_r, arr2_l, arr2_r;
        
        while(1) {
            int i = floor((l+r)/2.0);
            int j = k-i-2;
            
            
            
            arr1_l = i>=0?arr1[i]:-INT_MAX;
            arr2_r = (j+1)<n2?arr2[j+1]:INT_MAX;
            arr1_r = (i+1)<n1?arr1[i+1]:INT_MAX;
            arr2_l = j>=0?arr2[j]:-INT_MAX;
            
            // cout <<"\n"<< "i:"<<i<<" j:"<<j<<"\n";
            // cout << arr1_l << " | "<<arr1_r<<"\n";
            // cout << arr2_l << " | "<<arr2_r<<"\n";
            
            if(arr1_l <= arr2_r and arr2_l <= arr1_r){
                if((n1+n2)%2!=0)
                    return min(arr1_r, arr2_r);
                
                return (max(arr1_l, arr2_l)+min(arr1_r, arr2_r))/2.0;
            }
            
            else if(arr1_r < arr2_l)
                l = i+1;
            else
                r = i-1;
            
        }
        
        return -1;
        
        
    }
};