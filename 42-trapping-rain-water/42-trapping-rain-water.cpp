class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int water = 0;
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[i] > arr[st.top()]){
                int curr = st.top(); st.pop();
                
                if(st.empty()==false){
                    int dist = i-st.top()-1;
                    int left = st.top(), right = i;
                    
                    water += (min(arr[left], arr[right])-arr[curr])*dist;
                }
            }
            st.push(i);
            
            cout << water <<" ";
            
        }
        return water;
        
        
    }
};