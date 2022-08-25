class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
        int cnt1=0, cnt2=0, n=A.size();
        int val1, val2, i=0;
        
        while(i<n){
            if(A[i]==val1){
                cnt1++;
            }
            else  if(A[i]==val2){
                cnt2++;
            }
            else if(cnt1==0){
                cnt1++;
                val1 = A[i];
            }
            else if(cnt2==0){
                cnt2++;
                val2 = A[i];
            }
            else {
                cnt1--;
                cnt2--;
            }
            i++;
        }
        
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(A[i]==val1)cnt1++;
            else if(A[i]==val2)cnt2++;
        }
        
        vector<int>v;
        if(cnt1 > n/3 )v.push_back(val1);
        if(cnt2 > n/3 )v.push_back(val2);

        return v;
        
    }
};