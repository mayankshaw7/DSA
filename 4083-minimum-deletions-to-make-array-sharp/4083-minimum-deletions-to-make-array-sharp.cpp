class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int ops=0;
        int n=nums.size();
        int curr=nums[0];
        if(n==1) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                ops++;
            }
            // if(nums[i]^curr==0){
            //     ops++;
            // }else{
            //     curr=nums[i];
            // }
        }
        return ops;
    }
};