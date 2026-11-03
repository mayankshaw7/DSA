class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int maxi=*max_element(nums.begin(),nums.end());
        for(auto it:nums){
            sum+=(maxi-it);
        }
        return sum;
    }
};