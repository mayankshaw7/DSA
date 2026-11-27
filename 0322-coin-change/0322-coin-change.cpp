// striver series of DP -20
//understood everything with my own 
class Solution {
public:
    int helper(vector<vector<int>>& dp, vector<int>& coins, int idx,
               int target) {
        if (idx == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            return 1e9;
        }
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int nottake = helper(dp, coins, idx - 1, target);
        int take = INT_MAX;
        if (target >= coins[idx]) {
            take = 1 + helper(dp, coins, idx, target - coins[idx]);
            //1 + is for counting the coins 
        }
        return dp[idx][target] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = helper(dp, coins, n - 1, amount);
        if (ans == INT_MAX || ans == 1e9)
            ans = -1;
        return ans;
    }
};