class Solution {
public:
    vector<int> eventualSafeNodes1(int V, vector<vector<int>> adj) {
        vector<int> adjr[V];
        vector<int> id(V);
        for(int i  = 0; i < V; i++){
            for(auto it : adj[i]){
                adjr[it].push_back(i);
                id[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(id[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto i : adjr[node]){
                id[i]--;
                if(id[i]==0){
                    q.push(i);
                }
                
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        return eventualSafeNodes1(graph.size(), graph);
    }
};