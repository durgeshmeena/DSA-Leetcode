class Solution {
public:
    
    vector<int>parent;
    
    int find(int x){
        if(x==parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int xx = find(x);
        int yy = find(y);
        if(xx != yy){
            parent[yy] = xx;
        }
    }
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i]=i;
        
        for(auto e:pairs){
            int x = parent[e[0]];
            int y = parent[e[1]];
            if(x != y){
                Union(x,y);
            }
            
        }
        
        // for(int i=0; i<n; i++){
        //     cout << i <<":"<<parent[i]<<" ";
        // }
        
        unordered_map<int, string> team;
        
        for(int i=0; i<n; i++){
            team[find(i)] += s[i];
        }
        
        
        
        // for(auto str : team){
        //     sort(str.second.rbegin(), str.second.rend());
        // }
        
        for(auto a:team){
            sort(a.second.rbegin(), a.second.rend());
            team[a.first] = a.second;
            // cout << a.first << " : "<< a.second << "\n";
           
        }
        
        for(auto a:team){
            cout << a.first << " : "<< a.second << "\n";
           
        }
        
        string str="";
        
        for(int i=0; i<n; i++){
            str += team[find(i)].back();
            team[find(i)].pop_back();
        }
        
        return str;
        
        
        
        
        
        
        
    }
};