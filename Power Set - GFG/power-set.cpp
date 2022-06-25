// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    
	    vector<string>v;
	    int n;
	    string s;
	    
	    void dfs(int i, string str){
	        if(i==n){
	            v.push_back(str);
	            return;
	        }
	        dfs(i+1, str+s[i]);
	        dfs(i+1, str);
	            
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    n = s.size();
		    this->s = s;
		    
		    dfs(0,"");
		    sort(v.begin(), v.end());
		    vector<string> u(v.begin()+1, v.end());
		    return u;
		    
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