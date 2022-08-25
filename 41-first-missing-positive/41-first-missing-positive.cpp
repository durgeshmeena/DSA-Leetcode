class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int n = A.size();

        int i=0;
        while(i<n){
            if(A[i]<=0 || A[i]>n || A[i]==i+1)i++;
            else{
                int tmp=A[A[i]-1];
                if(tmp != A[i]){
                    A[A[i]-1] = A[i];
                    A[i] = tmp;
                }
                else
                    i++;
                
            }
        }

        for(int i=0; i<n; i++){
            if(A[i] != i+1)
                return i+1;
        }

        return n+1;        
    }
};