class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1;
        int area=0;
        
        while(l<r){
            area = max(area, min(height[l], height[r])*(r-l));
            
            height[l]<height[r]?l++:r--; 
            
        }
        
        return area;
    }
};