class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int distinct = 0, res = 0;
        
        int i = 0; //i-> start index; j-> end index :representing window
        for(int j=0; j<fruits.size(); j++){
            count[fruits[j]]++;
            if(count[fruits[j]]==1)distinct++;

            while(distinct>2){
                count[fruits[i]]--;
                if(count[fruits[i]]==0)distinct--;
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};