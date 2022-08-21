class Solution {
public:
    int minNumberOfHours(int initialEnergy, int Exp, vector<int>& energy, vector<int>& experience) {
        int totalE = accumulate(energy.begin(), energy.end(), 1);
        auto it = max_element(experience.begin(), experience.end());
        int res = totalE - initialEnergy;
        res = res<0?0:res;

        int t=Exp, r=0, y=0;
        for(int i=0; i<experience.size(); i++){
            if(t<=experience[i]){
                y += experience[i]-t;
                r = 1;
                t = t + y;
            }
            t += experience[i];
        }
        
        int ans1 =  res + y + r;
        
        return ans1;
        
        int i=0, n=experience.size();
        while(i<n){
            if(Exp <= experience[i]){
                res++;
                Exp++;
            }
            else{
                Exp += experience[i];
                i++;
            };
                
        }
        
        int ans2 = res;
        
        cout <<ans1 <<" "<< ans2 ;
        
        return res;
        
    }
};