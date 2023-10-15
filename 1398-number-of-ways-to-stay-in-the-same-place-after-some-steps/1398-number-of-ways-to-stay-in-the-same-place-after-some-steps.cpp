class Solution {
public:
    const int MOD = 1000000007;

    int solve(int steps, int i, int arrLen, vector<vector<int>> &dp) {
        if (i < 0 || i >= arrLen) {
            return 0;
        }
        if (i == 0 && steps == 0) {
            return 1;
        }
        if (i != 0 && steps == 0) {
            return 0;
        }

        if (dp[steps][i] != -1) {
            return dp[steps][i];
        }

        long long left = solve(steps - 1, i - 1, arrLen, dp) % MOD;
        long long right = solve(steps - 1, i + 1, arrLen, dp) % MOD;
        long long stay = solve(steps - 1, i, arrLen, dp) % MOD;

        return dp[steps][i] = (left + right + stay) % MOD;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, -1));
        return solve(steps, 0, arrLen, dp);
    }
};
