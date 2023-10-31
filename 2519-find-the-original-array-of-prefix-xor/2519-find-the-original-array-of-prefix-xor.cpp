class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int i = 0;
        int j = 1;
        vector<int> ans;
        ans.push_back(pref[0]);
        while(j < pref.size()){
            ans.push_back(pref[i]^pref[j]);
            i++;
            j++;
        }

        return ans;
    }
};