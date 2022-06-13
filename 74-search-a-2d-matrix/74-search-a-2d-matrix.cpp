class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int trgt) {
        int r = arr.size()-1;
        int c = arr[0].size()-1;
        
        int i=0, j=c;
        
        while(i>=0 and i<=r and j>=0 and j<=c){
            
            cout << "i=" << i << " j=" << j << "-->" << arr[i][j] << "\n";
            
            if(arr[i][j]==trgt)
                return true;
            else if (arr[i][j]<trgt)
                i++;
            else if(arr[i][j]>trgt)
                j--;
            
        }
        return false;
        
    }
};