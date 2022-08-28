class Solution {
public:
    int triangleNumber(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        long long sum=0;
        int k;
        for(int i=0; i<n-2; i++){
            if(A[i]==0) continue;
            k=i+2;
            for(int j=i+1; j<n-1; j++){
                while(k<n && A[i]+A[j] > A[k]){
                    k++;
                }
                sum += k-j-1;  
            }
        }
        
        return sum;
    }
};