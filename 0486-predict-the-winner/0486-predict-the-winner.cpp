class Solution {
public:
    int solve(vector<int>&nums,int i,int j,int turn){
        int n=nums.size();
        if(i>=n || j<0)return 0;
        if(i>j)return 0;
        
        if(turn){
            return max(nums[i]+solve(nums,i+1,j,0),nums[j]+solve(nums,i,j-1,0));
        }
        else return min(-nums[i]+solve(nums,i+1,j,1),-nums[j]+solve(nums,i,j-1,1));
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        int i=0,j=nums.size()-1,turn=1;
        int ans=solve(nums,i,j,turn);
        cout<<ans<<endl;
        if(ans>=0)return true;
        return false;
        
        
        
    }
};