class Solution {
public:
    const long long MOD = 1e9 + 7;
    map<string, long long> mapp;

    long long solve(int n, char i) {
        if (n == 1) {
            return 1LL; // Use long long here
        }

        string key;
        key.push_back(i);
        key += to_string(n);
        if (mapp.find(key) != mapp.end()) {
            return mapp[key];
        }

        long long total = 0LL; // Use long long here

        if (i == 'a') {
            total += (solve(n - 1, 'e') % MOD);
        } else if (i == 'e') {
            total += ((solve(n - 1, 'a') + solve(n - 1, 'i')) % MOD);
        } else if (i == 'i') {
            total += ((solve(n - 1, 'a') + solve(n - 1, 'e') + solve(n - 1, 'o') + solve(n - 1, 'u')) % MOD);
        } else if (i == 'o') {
            total += ((solve(n - 1, 'i') + solve(n - 1, 'u')) % MOD);
        } else if (i == 'u') {
            total += (solve(n - 1, 'a') % MOD);
        }

        return mapp[key] = total % MOD; // Take modulus here
    }

    int countVowelPermutation(int n) {
        vector<char> vow{'a', 'e', 'i', 'o', 'u'};
        long long total = 0LL; // Use long long here
        for (auto i : vow) {
            total += (solve(n, i) % MOD);
        }
        return total % MOD; // Take modulus here
    }
};
