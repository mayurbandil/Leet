class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sum = 0;

                for(int a = -k; a<=k; a++){
                    for(int b = -k; b<=k; b++){
                        int nr = i+a;
                        int nc = j+b;
                    if(nr>=0 && nc>=0 && nr<n && nc<m){
                        sum+=mat[nr][nc];
                    }
                    }
                }

                
                ans[i][j] = sum;
            }
        }

        return ans;
        
    }
};