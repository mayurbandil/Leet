class Solution {
public:
    int bfs(vector<vector<int>> & grid, vector<vector<int>> &vis, int n, int m, int i, int j){
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        vector<int> dr{-1, +1, 0, 0};
        vector<int> dc{0, 0, +1, -1};
        vis[i][j]=1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            cnt++;
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr>=0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                    q.push({nr, nc});
            vis[nr][nc] = 1;

                }
            }

        }

        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                  ans = max(ans, bfs(grid, vis, n, m, i, j));
                }
            }
        }

        return ans;
    }
};