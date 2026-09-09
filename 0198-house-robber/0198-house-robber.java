class Solution {
    public int rob(int[] nums) {
        int n=nums.length;
        int []dp=new int[n+1];
        Arrays.fill(dp,0);
        // list<Integer>vec=new ArrayList<>();
        dp[0]=0;
        dp[1]=nums[0];
        for(int i=2;i<=n;i++){

            int nottake=0+dp[i-1];
            int take=Integer.MIN_VALUE;
            if(i>1)
             take=nums[i-1]+dp[i-2];
            dp[i]=Math.max(take,nottake);
        }
        return dp[n];
    }
}