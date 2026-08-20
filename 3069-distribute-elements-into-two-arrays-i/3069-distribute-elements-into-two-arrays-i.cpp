class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> vec1;
        vector<int> vec2;

        int n = nums.size();
        if (n <= 2)
            return nums;
        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);

        for (int i = 2; i < n ; i++) {
            if (vec1.back()>vec2.back()) {
                vec1.push_back(nums[i]);
            } else {
                vec2.push_back(nums[i]);
            }
        }

        int m = vec1.size();
        int k = vec2.size();
        int i = 0;
        vector<int>ans;

        while (i < m) {
           ans.push_back(vec1[i]);
            i++;
        }

        i=0;
        while (i < k) {
            ans.push_back(vec2[i]);
            i++;
        }


        return ans;
    }
};