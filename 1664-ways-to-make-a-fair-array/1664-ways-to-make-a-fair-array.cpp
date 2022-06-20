class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int sum=0, eSUm=0, oSum=0;
        int n = nums.size();
        if(n<2)
            return 1;
        
        vector<int>esum, osum;
        esum.push_back(0);
        osum.push_back(0);
        sum=nums[0]+nums[1];
        
        for(int i=0; i<n; i++) {
            sum+=nums[i];
            if(i%2==0)
                esum.push_back(esum.back()+nums[i]);
            else
                osum.push_back(osum.back()+nums[i]);
        }
        
        // cout <<"\n";
        // for(auto e:esum)
        //     cout << e <<" ";
        // cout <<"    ";
        // for(auto o:osum)
        //     cout << o <<" ";
        
        auto evenSum = [&](int i){
            int j = (i+1)/2;
            return esum[j] + osum.back()-osum[j];
        };
        
        auto oddSum = [&](int i){
            int oS;
            int j = (i+1)/2;
            
            if(i%2==0)
                oS = osum[j] + esum.back()-esum[j+1];
            else
                oS = osum[j-1] + esum.back()-esum[j];
            return oS;
        };
        
        int cnt=0;
        for(int i=0; i<n; i++){
            
            if(evenSum(i) == oddSum(i))
                cnt++;
            
        }
        
        
        
        
        return cnt;
        
    }
};