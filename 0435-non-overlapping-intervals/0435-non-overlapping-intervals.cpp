class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        
        if(a[1]==b[1])return a[0]>b[0];
        return a[1]<b[1];
                
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),cmp);
        
        int cnt=1;
        vector<int>temp=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i][0]>=temp[1])
            {
                cnt++;
                temp=v[i];      
            }
           
        }
        return v.size()-cnt;
        
    }
};