class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 1e9;
        int n = nums.size();
        set<int> st (begin(nums), end(nums));
        vector<int> temp( begin(st), end(st));
        for(int i = 0; i < temp.size(); i++){
            int left_range  = temp[i];
            int right_range = left_range + n - 1;
            
            int j = upper_bound(begin(temp), end(temp), right_range) - begin(temp);
            
            int in_range  = j - i;
            int out_range = n - in_range;
            
            ans = min(ans, out_range);
        }

        return ans;
    }
};