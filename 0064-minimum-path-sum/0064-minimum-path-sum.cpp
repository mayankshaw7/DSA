//this is my Favrite QUestion buddy
class Solution {
public:
    int m, n;
    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solve(0, 0, grid, memo);
    }
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& memo) {
        if (i == m - 1 && j == n - 1)
            return grid[i][j];

        if (i >=m || j >=n) {
            return 1e9;
        }
        if (memo[i][j] != -1)
            return memo[i][j];
        int right = solve(i + 1, j, grid, memo);
        int down = solve(i, j + 1, grid, memo);
        return memo[i][j]=grid[i][j] + min(right, down);
    }
};
/*this will give the TLE so performing WIth Memoization approach here in
class Solution {
public:
vector<pair<int,int>>dir={{0,-1},{1,0},{0,1},{-1,0}};
    int m,n;
    int minPathSum(vector<vector<int>>& grid) {
        int minsum=INT_MAX;
         m=grid.size();
         n=grid[0].size();
        //backtracking bhi hoga isme
        dfs(0,0,grid,minsum,grid[0][0]);
        return minsum;
    }
    void dfs(int i,int j,vector<vector<int>>& grid,int &minsum,int sum){
        if(i==m-1 && j==n-1){
            minsum=min(minsum,sum);
            return;
        }
        if(grid[i][j]=='#') return;
        int temp=grid[i][j];

        for(auto it:dir){
            int i_=i+it.first;
            int j_=j+it.second;

            if(i_>0 && j_>0 && i<m && j<n){
                dfs(i_,j_,grid,sum+grid[i_][j_]);
            }
        }

    }
};
*/
