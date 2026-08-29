//classic problem of DP in the varint of HOuse Robber 

class Solution {
    public int deleteAndEarn(int[] nums) {
        int maxi=0;
        for(int num:nums){
            maxi=Math.max(num,maxi);
        }
        //maxi + 1 inorder to use that as a index
        int [] arr=new int[maxi+1];
        
        for(int num:nums){
            arr[num]+=num;
        }

        int [] dp=new int[maxi+1];
        Arrays.fill(dp,-1);
        return solve(dp,maxi,arr);
    }
    private static int solve(int []dp,int idx,int []arr){
        if(idx==0) return arr[0];
        if(idx<0) return 0;

        if(dp[idx]!=-1){
            return dp[idx];
        }
        int take=arr[idx]+solve(dp,idx-2,arr);
        int nottake=0+solve(dp,idx-1,arr);

        return dp[idx]=Math.max(take,nottake);
    }
}