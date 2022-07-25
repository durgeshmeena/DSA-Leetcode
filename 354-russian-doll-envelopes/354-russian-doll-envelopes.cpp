class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&v1, vector<int>&v2){
            if(v1[0]==v2[0])
                return v1[1]>v2[1];
            return v1[0] < v2[0];
        });
        
        int n = envelopes.size();
        
        
//         vector<int> dp(n,1);
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<i; j++){
//                 if(envelopes[i][1] > envelopes[j][1]){
//                     dp[i] = max(dp[i], 1+dp[j]);
                    
//                 }
                    
//             }
//         }
        
//         return *max_element(dp.begin(), dp.end());
        
        
        vector<int> arr;
        arr.push_back(envelopes[0][1]);
        
        for(int i=1; i<n; i++){
            if(envelopes[i][1]>arr[arr.size()-1])
                arr.push_back(envelopes[i][1]);
            else{
                auto it = lower_bound(arr.begin(), arr.end(), envelopes[i][1]);
                *it = envelopes[i][1];
            }
        }
        
        return arr.size();
       
        
        
            
        
    }
};