class Solution {
public:
    int res=INT_MAX;
    int val;
    
    int minSteps(int n) {
        val = n;
        if(n<2)return 0;
        solve(1, 1, 1);
        return res;
    }
    
    void solve(int prev, int i, int step){
        if(i == val){
            res = min(res, step);
            return;
        }
        else if(i>val)return;
        
        solve(prev, i+prev, step+1);
        solve(i, i+i, step+2);
    }
};