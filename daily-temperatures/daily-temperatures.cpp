class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n = tem.size();
        stack<int> st;
        vector<int>arr(n);
        st.push(n-1);
        
        for(int i=n-2; i>=0; i--){
            if(tem[i] < tem[st.top()]){
                arr[i] = st.top()-i;
                st.push(i);
            }
            else{
                while(!st.empty() and tem[i] >= tem[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    arr[i] = 0;
                    st.push(i);
                }else{
                    arr[i] = st.top()-i;
                    st.push(i);
                }
                    
                
            }
        }
        return arr;
    }
};