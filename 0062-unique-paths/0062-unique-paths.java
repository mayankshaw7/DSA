//pure dp approach 
class Solution {
    public int uniquePaths(int m, int n) {
        //solving using dp only 
        int[][] dp = new int[m][n];

        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int down = 0, right = 0;
                if (i > 0)
                    down = dp[i - 1][j];
                if (j > 0)
                    right = dp[i][j - 1];
                dp[i][j] = down + right;
            }
        }
        return dp[m - 1][n - 1];
    }
}
/*
//Recursion + memoization call here in t

class Solution {
    public int uniquePaths(int m, int n) {
        //solving using dp only 
        int[][] dp = new int[m][n];
        for (int[] row : dp)
            Arrays.fill(row, -1);
        dp[0][0] = 1;
        return f(dp, m - 1, n - 1);
    }

    private int f(int[][] dp, int i, int j) {
        if (i < 0 || j < 0)
            return 0;

        int up = 0, left = 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        up = f(dp, i - 1, j);
        left = f(dp, i, j - 1);
        return dp[i][j] = up + left;
    }
}
*/