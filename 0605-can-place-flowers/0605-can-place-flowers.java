//suggest ed this greedy approach
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        int s = flowerbed.length;

        for (int i = 0; i < s; i++) {
            if (flowerbed[i] == 0) {
                boolean prevEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                boolean nextEmpty = (i == s - 1) || (flowerbed[i + 1] == 0);

                if (prevEmpty && nextEmpty) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n) return true;
                }
            }
        }

        return count >= n;
    }
}
//below was mycode vut not rcoommended 
/*
class Solution {
    public boolean canPlaceFlowers(int[] f, int n) {
        int s = f.length;
        if (n > s) return false;

        int cnt_0 = 0;
        int having = 0;
        boolean first_idx = true; // Tracks if current zero sequence started at index 0

        for (int i = 0; i < s; i++) {
            if (f[i] == 0) {
                cnt_0++;
            } else {
                if (first_idx) {
                    having += cnt_0 / 2; // Leading zeros bounded by edge and '1'
                    first_idx = false;
                } else {
                    having += (cnt_0 - 1) / 2; // Zeros bounded by two '1's
                }
                cnt_0 = 0;
            }
        }

        // Process trailing zeros after loop ends
        if (cnt_0 > 0) {
            if (first_idx) {
                having += (cnt_0 + 1) / 2; // Entire array is zeros
            } else {
                having += cnt_0 / 2; // Trailing zeros bounded by '1' and edge
            }
        }

        return having >= n;
    }
}
*/