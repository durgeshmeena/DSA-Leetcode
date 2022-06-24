class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {};
        int maxCount = 0, res = 0;
        int i=0;
        
        for(int j=0; j<s.size(); j++){
            count[s[j]-'A']++;
            if(count[s[j]-'A']>maxCount)maxCount = count[s[j]-'A'];
            
            while(j-i+1 - maxCount > k){
                count[s[i++]-'A']--;
                // maxCount = *max_element(count, count+26);
            }
            
            res = max(res, j-i+1);
        }
        
        return res;
            
    }
};