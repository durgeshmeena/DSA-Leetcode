class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
    
        int r = arr.size(),
            c = arr.size(),
            lo = arr[0][0],
            hi = arr[r-1][c-1];        
    
        auto cnd = [&](int x){
            int cnt=0;
            for(int i=0; i<r; i++) {
                int j = c-1;
                while(j>=0 and arr[i][j]>x)j--;
                cnt += j+1;
            }  
            if(cnt>=k)
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