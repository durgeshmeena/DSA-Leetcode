class Solution {
public:
    
    int len;
    long long cnt=0;
    int DP[10005][7][7];
    int m = 1000000007;
    // DP[pos][lst_dgt][2nd_lst_dgt];
    
    long long solve(int pos, int first, int second){
        if(pos>=len)
            return 1;
        
        if(DP[pos][first][second] != -1)
            return DP[pos][first][second];
        
        int res=0;
        
        for(int dgt=1; dgt<7; dgt++){
            if(dgt!=first and dgt!=second and (gcd(dgt, first)==1 || first==0))
                res = ( res + solve(pos+1, dgt, first) )%m;
            
        }

        return DP[pos][first][second] = res;
        
    }
    
    int distinctSequences(int n) {
        if(n==1)
            return 6;
        len = n;
        memset(DP, -1, sizeof(DP));
        return solve(0,0,0);
        
    }
};