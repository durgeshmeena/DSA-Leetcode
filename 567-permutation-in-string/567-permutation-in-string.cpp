class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count;
        int k=s1.size();
        
        for(auto c:s1)
            count[c]++;
        int remain = count.size();

        
        int i = 0;
        for(int j=0; j<s2.size(); j++){
            count[s2[j]]--;
            if(count[s2[j]]==0)remain--;
            
            if(j-i+1<k)
                continue;

            
            if(remain==0)
                return true;
            
            count[s2[i]]++;
            if(count[s2[i]]==1)remain++;
            i++;
            
        }
        return remain==0;
    }
};