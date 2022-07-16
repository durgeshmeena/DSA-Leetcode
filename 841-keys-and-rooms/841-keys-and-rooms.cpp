class Solution {
public:
    
    void DFS(int i, vector<int>& vis, vector<vector<int>>& rooms){
        
        for(auto next:rooms[i]){
            if(!vis[next]){
                vis[next]=1;
                DFS(next, vis, rooms);
            }
        }
        
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<int>vis(n);
        vis[0] = 1;
        DFS(0, vis, rooms);
        
        return *min_element(vis.begin(), vis.end()) == 1;
    }
};