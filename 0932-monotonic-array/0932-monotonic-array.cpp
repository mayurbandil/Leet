class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        for(int i = 0; (i+1)<nums.size(); i++){
            if(nums[i+1]<nums[i]){
                inc = false;
                break;
            }
        }
        for(int i = 0; (i+1)<nums.size(); i++){
            if(nums[i+1]>nums[i]){
                dec = false;
                break;
            }
        }

        return inc+dec;
        
    }
};