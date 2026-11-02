//just similar like the PODT of the leetcode dated- 29/4/26
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //taking the median of an array
        sort(begin(nums),end(nums));
        int mid_idx=nums.size()/2;
        int mid=nums[mid_idx];
        int diff=0;
        for(int i=0;i<nums.size();i++){
            diff+=abs(mid-nums[i]);
        }
        return diff;
    }
};