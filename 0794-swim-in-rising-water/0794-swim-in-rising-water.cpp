class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, 1e9));
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        dis[0][0] = grid[0][0];
        vis[0][0] = 1;
        q.push({grid[0][0], {0, 0}});
        while(!q.empty()){
            int ele = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(row == n-1 && col == n-1){
                return dis[row][col];
            }
            vector<int> dr{0,1,0,-1};
            vector<int> dc{1,0,-1,0};

            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                   if(grid[nr][nc]>ele){
                       dis[nr][nc] = grid[nr][nc];
                       q.push({dis[nr][nc], {nr, nc}});
                       vis[nr][nc] = 1;
                   }else{
                       dis[nr][nc] = ele;
                       q.push({ele, {nr, nc}});
                       vis[nr][nc] = 1;
                   }
                }
            }
        }
        return -1;
    }
};