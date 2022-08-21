class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<char, int> count;
        
        for(auto c:num)
            count[c]++; 
        
        string s1="", s2="", s_mid="";
        
        for(auto x:count){
            int cnt = x.second/2;
            while(cnt--)
                s1 += x.first;
        }
        
        sort(s1.begin(), s1.end());
        
        auto c = '0';
        for(auto x:count){
            if(x.second%2==1 and x.first>c)
                c = x.first;
        }
        
        if(s1[0]=='0' and s1.back()=='0'){
            string ans = "0";
            if(c>ans[0])ans=c;
            return ans;
        }
        
        
        s2 = s1;
        reverse(s2.begin(), s2.end());
        
        if(c>'0')s_mid=c;
        else if(count['0']%2==1)s_mid='0';
        
        return s2 + s_mid + s1;
        
        
    }
};