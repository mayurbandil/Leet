class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> evenNums;
        vector<int> oddNums;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2==0){
                evenNums.push_back(nums[i]);
            }
            else{
                oddNums.push_back(nums[i]);
            }
        }

        for(int i = 0; i<oddNums.size(); i++){
            evenNums.push_back(oddNums[i]);
        }

        return evenNums;
    }
};