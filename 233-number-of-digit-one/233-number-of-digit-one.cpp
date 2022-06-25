class Solution {
public:
    string s;
    int DP[12][12][2];
    int n;
    
    int solve(int pos, int cnt, bool f){
        if(pos==n)
            return cnt;
        
        if(DP[pos][cnt][f] != -1)
            return DP[pos][cnt][f];
        
        int res = 0;
        int LMT = (f==false) ? stoi(s.substr(pos,1)) : 9;
        
        for(int dgt=0; dgt<=LMT; dgt++){
            int ncnt=cnt, nf=f;
            if(f==0 and dgt<LMT) nf=true;
            if(dgt==1)ncnt++;
            
            res += solve(pos+1, ncnt, nf);
                
        }
        return DP[pos][cnt][f] = res;
        
    }
    
    int countDigitOne(int num) {
        if(num==0)
            return 0;
        
        this->s = to_string(num);
        this->n = s.size();
        
        memset(DP, -1, sizeof(DP));
        
        return solve(0,0,false);
        // return 0;
    }
};