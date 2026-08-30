class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<pair<int,int>>vec;

        int min_idx = 0, max_idx = 0,n=nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[min_idx] > nums[i])
                min_idx = i;
            if (nums[max_idx] < nums[i])
                max_idx = i;
        }
        int left_min=min_idx+1;
        int left_max=max_idx+1;

        int right_min=n-min_idx;
        int right_max=n-max_idx;

        int first=min(left_min,right_min);
        int second=min(left_max,right_max);

        return min({first+second, max(left_min,left_max),max(right_min,right_max)});
    }
};