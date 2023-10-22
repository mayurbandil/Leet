class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k;
        int j = k;
        int n = nums.size();
        int currMin = nums[k];
        int result = nums[k];
        while(i!=0 || j!=n-1){
            int leftval = (i>0) ? nums[i-1] : 0;
            int rightval = (j<n-1)? nums[j+1] : 0;
            if(leftval<rightval){
                j++;
                currMin = min(currMin, nums[j]);

            }else{
                i--;
                currMin = min(currMin, nums[i]);
            }

            result = max(result, currMin*(j-i+1));
        }

        return result;
    }
};