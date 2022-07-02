class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size(), dist;
        stack<int> st;
        vector<int>area(n);
        
        auto print = [&](){
            for(auto x:area)
                cout << x <<" ";
            cout <<"\n";
        };
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                area[st.top()] += arr[st.top()]*(st.top()-i-1);
                st.pop();
                // print();
            }
            if(st.empty())
                dist = n-i;
            else
                dist = st.top()-i;
            
            area[i] = arr[i]*dist;
            st.push(i);
            
            // print();
            
        }
        
        int i = st.top();
        while(!st.empty()){
            area[st.top()] += arr[st.top()]*(st.top()-i);
                st.pop();
                // print();
        }
        
        print();
        return *max_element(area.begin(), area.end());
        
    }
};