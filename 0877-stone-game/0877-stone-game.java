class Solution {
    public boolean stoneGame(int[] piles) {
        int n=piles.length;
        int [][]dp=new int[n][n];
        for(int []row:dp){
            Arrays.fill(row,-1);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }
        //Alice total got it 
        int res= solve(piles,dp,0,n-1);
        return res>=Math.floor(sum/2);
    }
    private int solve(int [] piles,int [][]dp,int i,int j){
        if(i<0 || j<0 || i>j) return 0;
        if(i==j) return piles[i];
        if(dp[i][j]!=-1) return dp[i][j];
        //alice choose from left that is i
        int take_i=piles[i]+ Math.min(solve(piles,dp,i+2,j), solve(piles,dp,i+1,j-1));
        //Alice choose from right that is j
        int take_j=piles[j]+ Math.min(solve(piles,dp,i+1,j-1), solve(piles,dp,i,j-2));

        return dp[i][j]=Math.max(take_i,take_j);
    }
}