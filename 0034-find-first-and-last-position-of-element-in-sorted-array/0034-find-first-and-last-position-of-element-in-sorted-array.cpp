class Solution {
public:
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> nums1;
    vector<int> nums2;
    int i = 0;
    int j = nums.size()-1;
    if(nums.size()==0){
        nums1.push_back(-1);
        nums1.push_back(-1);
    }
for (int i = 0; i < nums.size(); i++)
{
    if(nums[i] == target){
        nums1.push_back(i);
    }
    
}
if (nums1.size() == 0)
{
    nums1.push_back(-1);
    nums1.push_back(-1);
    return nums1;
}

else if(nums1.size()==1){
    nums1.push_back(nums1[0]);
    return nums1;
}

else if(nums1.size()==2){
    return nums1;
}

else{
    nums2.push_back(nums1[0]);
    nums2.push_back(nums1[nums1.size()-1]);
}

return nums2;
}
};