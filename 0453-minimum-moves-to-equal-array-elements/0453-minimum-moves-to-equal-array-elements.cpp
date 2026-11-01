class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int cnt=0,n=nums.size();
        
        for(int i=0;i<n;i++){
            int val=cnt+nums[i];
            int df=val-nums[n-1]-cnt;
            if(df<=0) break;
            cnt+=df;
        }
        return cnt;
    }
};