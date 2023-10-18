class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for(auto i : relations){
            int from = i[0]-1;
            int to = i[1]-1;
            adj[from].push_back(to);
            inDeg[to]++;
        }

        queue<int> q;
        vector<int> dist(n, 0);
        for(int i = 0; i < n; i++){
            if(inDeg[i]==0){
                q.push(i);
                dist[i]=time[i];
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : adj[node]){
            inDeg[i]--;
            dist[i] = max(dist[i], dist[node]+time[i]);
                if(inDeg[i]==0){
                    q.push(i);
                }
            }
        }

        return *max_element(dist.begin(), dist.end());
        
    }
};