class Solution {
public:
    // vector<int> height;
    // int areaTill = INT_MIN;
    // int area(int l, int r){
    //     if (l >= r)return 0;
    //     else if (l == r-1)return min(height[l], height[r]);
    //     return max( min(height[l], height[r])*(r-l), max(area(l+1, r), area(l, r-1) ));
    // }
    
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int area=INT_MIN;
        while(l<=r){
            if (l >= r) break;
            else if (l == r-1)area = max(area, min(height[l], height[r]) );
            
            area = max(area, min(height[l], height[r])*(r-l) );
            
            if (height[l] < height[r])l++;
            else
                r--;
            
        }
        return area;
    }
};