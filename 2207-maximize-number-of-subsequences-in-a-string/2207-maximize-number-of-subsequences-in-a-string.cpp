class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long ans = 0;
        long long y_cnt = 0;
        long long x_cnt = 0;

        for (long long i=text.size()-1; i>=0; i--) {
            
            if (text[i] == pattern[1]) y_cnt++;
            if (text[i] == pattern[0]) x_cnt++;

            if (text[i] == pattern[0]) ans += y_cnt;

        }
        
        // long long m = max(x_cnt, y_cnt) + ans;
        if (pattern[0] == pattern[1])return x_cnt*(x_cnt+1)/2;
        return max(x_cnt, y_cnt) + ans;
        
    }
};