class Solution {
public:
    string minWindow(string s, string t) {
        int min_j=INT_MAX, min_i=1, remain;
        unordered_map<char, int> count;
        
        for(auto c:t){
            count[c]++;
        }
        remain = count.size();
        
        int i=0;
        for(int j=0; j<s.size(); j++){
           
            count[s[j]]--;
            if(count[s[j]]==0)remain--;
            
            while(remain==0){
                if(j-i < min_j-min_i){
                    min_j=j;
                    min_i=i;
                }
                
                count[s[i]]++;
                if(count[s[i]]>0)remain++;
                i++;
                    
            }
        }
        
        // return "";
        return min_j==INT_MAX?"":s.substr(min_i, min_j-min_i+1);
    }
};