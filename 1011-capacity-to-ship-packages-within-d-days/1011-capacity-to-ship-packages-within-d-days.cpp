class Solution {
public:
    
    bool isValid(vector<int>& arr, int n, int k, int mx){
        int sm=0;
        int cnt=1;
        
        for(int i=0; i<n;i++){
            sm += arr[i];
            if(sm>mx){
                sm = arr[i];
                cnt++;
            }
            if(cnt>k)
                return false;
        }
        
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int start,end,res=-1;
        int n = weights.size();
        vector<int>prefix(n);
        prefix[0] = start = weights[0];
        
        for(int i=1; i<n;i++){
            start = max(start, weights[i]);
            prefix[i] = prefix[i-1]+weights[i];
        }
        
        end = prefix[n-1];
        
        while(start<=end){
            int mid = start + (end-start)/2;
            bool cnd = isValid(weights, n, days, mid);
            
            cout << mid << " -> "<<cnd <<"\n";
            
            if(cnd){
                res = mid;
                end = mid-1;
            }
            else {
                start = mid+1;
            }
        }
        
        return res;
        
    }
};