class Solution {
public:
    int totalHammingDistance(vector<int>& A) {
        int n = A.size();
        int a = 32;
        long long res = 0;
        int M = 1e9+7;
        while(a--){
            int one=0;
            for(int i=0; i<n; i++){
                one += (A[i]&1);
                A[i] = A[i]>>1;
            }
            res += one*(n-one);
        }
        return res;        
    }
};