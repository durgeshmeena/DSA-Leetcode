class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int i=0, n=num, cnt=0;
        string s = to_string(num);

        for(int j=0; j<s.size(); j++){
            if(j-i+1 <k){
               continue;
            }
            else if(j-i+1 == k){
                int d = stoi(s.substr(i, k));
                if(d)
                    cnt += num%d==0?1:0;
                i++;
            }
        }
        return cnt;
        
    }
};