class Solution {
    public int uniquePathsWithObstacles(int[][] o) {
        int m=o.length;
        int n=o[0].length;
        int [][] dp=new int[m][n];
        if(m==1 && n==1 && o[0][0]==1) return 0;

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //order really matters here 
                if(o[i][j]==1) {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0) {
                dp[i][j]=1;
                continue;
                }
                int right=0,down=0;
                if(i>0){
                    down=dp[i-1][j];
                }
                if(j>0){
                    right=dp[i][j-1];
                }
                dp[i][j]=right+down;
            }
        }
        return dp[m-1][n-1];
    }
}