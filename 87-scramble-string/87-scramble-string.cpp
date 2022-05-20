class Solution {
public:
    unordered_map<string, bool>dp;
        
    bool scrm(string s1, string s2) {
        
        if(s1.compare(s2) == 0)
            return true;
        else if (s1.size()<=1 or s2.size()<=1)
            return false;
        
        if(dp.find(s1+"_"+s2) != dp.end())
            return dp[s1+"_"+s2];
        
        int n = s1.size();
        bool flag = false;
        
        for(int i=1; i<n; i++) {
            
            bool cnd1 =  scrm(s1.substr(0, i), s2.substr(0, i))  && scrm(s1.substr(i, n-i), s2.substr(i, n-i));
                
            bool cnd2 =  scrm(s1.substr(0, i), s2.substr(n-i, i))  && scrm(s1.substr(i, n-i), s2.substr(0, n-i));
                
            if (cnd1==true || cnd2 == true) {
                flag = true;
                break;
            }
                  
        }
        
        return dp[s1+"_"+s2] = flag;
        
        
    }
    
    bool isScramble(string s1, string s2) {
        
     
        return scrm(s1, s2);
    }
};