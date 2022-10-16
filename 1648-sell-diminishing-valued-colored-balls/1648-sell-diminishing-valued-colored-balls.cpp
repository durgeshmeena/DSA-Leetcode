class Solution {
public:
    
    int MOD = 1e9+7;
    
    
    int maxProfit(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
       
        int l=0, h=*max_element(arr.begin(), arr.end());
        
        
        auto check = [&](int val){
            
            int count=0;
            for(auto x:arr){
                if(x > val){
                    count += x-val;
                }
                if(count >= k)return true;
                
            }
            // cout << val << "->" << count <<"\n";
            
            return false;
            
        };
        
        while(l<h){
            int mid = l+(h-l)/2;
            
            if(check(mid))
                l = mid+1;
            else
                h = mid;
        }
        
        int nVal = l, nK=k;
        int cost=0;
        for(auto x:arr){
            if(x>nVal){
                cost = (1ll*cost + sum(x, nVal))%MOD;
                nK -= (x-nVal);
            }
                
        }
        
        nVal;
        while(nK--){
            cost = (1ll*cost+nVal)%MOD;
        }
        return cost;
        
        
    }
    
    
    int sum(int n2, int n1=0){
        long long int diff =  (((1ll*n2*(n2+1))/2)%MOD-((1ll*n1*(n1+1))/2)%MOD)%MOD;
        return diff;
    }
    
    
    
};