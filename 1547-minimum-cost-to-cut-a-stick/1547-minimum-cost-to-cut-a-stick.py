class Solution:
    def minCost(self, n: int, cuts: list[int]) -> int:
        @lru_cache(None)
        def dp(i,j):
            return 0 if j-i<=1 else min(cuts[j]-cuts[i] +dp(i,k)+dp(k,j) for k in range(i+1,j))
        cuts.extend([0,n]);cuts.sort()
        return dp(0,len(cuts)-1)
        