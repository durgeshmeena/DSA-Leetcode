class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), res=0;
        unordered_map<char, int>count;
        
        int i=0;
        for(int j=0; j<n; j++){
            count[s[j]]++;
            while(count[s[j]]>1){
                count[s[i]]--;
                i++;
            }
            res = max(res, j-i+1);
        }
        
        return res;
        
    }
};