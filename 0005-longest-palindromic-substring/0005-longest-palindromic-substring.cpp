class Solution {
public:
    bool solve(string &s, int i, int j, vector<vector<int>> &dp){
        if(i>=j){
            return true;
        }

        if(s[i]!=s[j]){
            return false;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j] = solve(s, i+1, j-1, dp);
    }
    string longestPalindrome(string s) {
        int si = 0;
        int l = INT_MIN;
        vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));
        for(int i = 0; i <s.length(); i++){
            for(int j = i; j<s.length(); j++){
                if(solve(s, i, j, dp)){
                    if(j-i+1 > l){
                        l = j-i+1;
                        si = i;
                    }
                }
            }
        }

        return s.substr(si, l);
    }
};