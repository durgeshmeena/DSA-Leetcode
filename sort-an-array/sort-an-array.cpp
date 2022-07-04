class Solution {
public:
    
    vector<int> merge(vector<int> &s1, vector<int> &s2){
        int n1 = s1.size(), n2 = s2.size();
        vector<int> res(n1+n2);
        
        int i=0, j=0, k=0, e1,e2;
        
        while(k<n1+n2){
            e1 = i<n1 ? s1[i] : INT_MAX;
            e2 = j<n2 ? s2[j] : INT_MAX;
            
            
            res[k++] = e1<e2 ? i++, e1 : (j++, e2);
        }
        
        return res;
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        
        int p = nums.size()/2;
        vector<int> left(nums.begin(), nums.begin()+p);
        vector<int> right(nums.begin()+p, nums.end());
        
        vector<int>s1 = sortArray(left);
        vector<int>s2 = sortArray(right);
        return merge(s1,s2);
    }
};