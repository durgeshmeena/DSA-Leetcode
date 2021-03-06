class Solution {
public:
    
    vector<int> NGE_array(vector<int>& arr){
        int n = arr.size();
        vector<int>res(n,-1);
        
        for(int i=n-2; i>=0; i--){
            int j = i+1;
            
            while(j<n and arr[i] > arr[j]){
                if(res[j]==-1)
                    j = n;
                else
                    j += res[j];
            }
            if(j==n)res[i] = -1;
            else
                res[i] = j-i;
        }
        
        for(int i=n-1; i>=0; i--){
            if(res[i] != -1)
                res[i] = arr[i+res[i]];
        }
        
        return res;        
    }
    
    vector<int> NGR_stack(vector<int>& arr){
        int n = arr.size();
        vector<int>res(n, -1);
        stack<int>st;
        
        for(int i=n-1; i>=0; i--){
            while(st.size() and arr[i] > st.top() ){
                st.pop();
            }
            
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(arr[i]);
        }
        
        return res;
        
    }
    
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int> ngr2 = NGR_stack(nums2);
        vector<int> ngr2 = NGE_array(nums2);
        vector<int> res;
        
        for(auto ele:ngr2)
            cout << ele <<" ";
        
        for(auto x:nums1){
            auto ind = find(nums2.begin(), nums2.end(), x) - nums2.begin();
            int val = ngr2[ind];
            res.push_back(val);
        }
        
        return res;
        
    }
};