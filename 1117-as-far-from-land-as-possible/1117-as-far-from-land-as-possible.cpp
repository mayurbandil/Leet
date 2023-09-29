class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> dis(n, vector<int>(n, 0));
        queue<pair<int, pair<int, int>>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        vector<int> dr{-1, 0, 1, 0};
        vector<int> dc{0, 1, 0, -1};

        while(!q.empty()){
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            dis[row][col] = steps;
            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
        if(nr>=0 && nc>=0 && nr < n && nc < n && !vis[nr][nc] && grid[nr][nc]==0){
        q.push({steps+1, {nr, nc}});
        vis[nr][nc] = 1;
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dis[i][j]);
            }
        }

        if(ans == 0){
            return -1;
        }

        return ans;
    }


};