class Solution {
    public int candy(int[] ratings) {
        //using the greedy logic in order to solve this in two linear passes that are
        //check from left to right and then check from right to left 
        int n = ratings.length;
        //left to right
        int[] ans = new int[n];
        Arrays.fill(ans, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            }
        }
        //right to left traversal 
        //we also need to trace the same on coming from backend 
        //if it is already greater then no need to update it 
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                ans[i] = Math.max(ans[i], ans[i + 1] + 1);
            }
        }
        int sum = 0;
        for (int num : ans)
            sum += num;
        //space optimization is here
        return sum;
    }
}