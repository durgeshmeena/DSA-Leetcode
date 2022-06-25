// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n = s.size();
		    vector<string>v;
		    
		    
		    int power_set = pow(2, n);
		    
		    for(int i=0; i<power_set; i++){
		        
		        string str = "";
		        for(int j=0; j<n; j++){
		            if(i & (1<<j))
		                str += s[j];
		        }
		        if(str.length())
		            v.push_back(str);
		        
		    }
		    sort(v.begin(), v.end());
		    return v;
		    
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends