class UnionFindSet {
public:
    UnionFindSet(int n) : _parent(n) {
        for (int i=0; i<n; i++) {
            _parent[i] = i;
        }
    }
    
    void Union(int x, int y) {
        _parent[Find(x)] = _parent[Find(y)];
    }
    
    int Find(int x) {
        if (_parent[x] != x) {
            _parent[x] = Find(_parent[x]);
        }
        return _parent[x];
    }
    
private:
    vector<int> _parent;
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(), A.end());
        UnionFindSet ufs(n+1);
        for (int &a : A) {
            for (int k = 2; k <= sqrt(a); k++) {
                if (a % k == 0) {
                    ufs.Union(a, k);
                    ufs.Union(a, a / k);
                }
            }
        }
        
        unordered_map<int, int> mp;
        int ans = 1;
        for (int &a : A) {
            ans = max(ans, ++mp[ufs.Find(a)]);
        }
        return ans;
    }
};


// class Solution {
// public:
    
    
//     unordered_map<int, int> parent;
    
//     int findP(int u){
//         if(parent[u] == u)return u;
//         return parent[u] = findP(parent[u]);
//     }
    
//     void unite(int u, int v){
//         int up = findP(u);
//         int vp = findP(v);
//         if(up != vp){
//             parent[vp] = parent[up];
//         }
//     }
        
    
//     int largestComponentSize(vector<int>& nums) {
//         int n = nums.size();
        
//         sort(nums.begin(), nums.end());
        
//         for(int i=0; i<n; i++){
//             parent[nums[i]] = nums[i]; 
//         }
        
//         for(int i=0; i<n; i++)
//             for(int j=i+1; j<n; j++){
//                 // if(__gcd(nums[i], nums[j]) > 1){
//                 //     unite(nums[i], nums[j]);
//                 // }
//             }
        
//         int res=0;
//         unordered_map<int, int> count;
//         for(auto x:parent){
//             count[findP(x.second)]++;
//             res = max(res, count[x.second]);
//         }
//         return res;
        
//     }
// };