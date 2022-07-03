class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int area = 0;
        
        for(int i=n-1; i>-2; i--){
            while(st.size() && ( i<0 || height[i] < height[st.top()])){
                int h = height[st.top()]; st.pop();
                int w = st.empty() ? n-i-1 : st.top()-i-1;
                area = max(area, h*w);
            }
            st.push(i);
        }
        
        return area;
    }
};