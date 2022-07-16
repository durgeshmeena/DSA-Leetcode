class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>score(n+1);
        
        for(auto v:trust){
            score[v[0]]--;
            score[v[1]]++;
        }
        
        auto it = max_element(score.begin()+1, score.end());
        
        return *it != n-1 ? -1 : it - score.begin();
        
        
    }
};