import java.util.Arrays;

class Solution {
    public void wiggleSort(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        
        int[] temp = new int[n];
        
        // Midpoint splits smaller half and larger half
        int left = (n - 1) / 2; // Last index of smaller half
        int right = n - 1;       // Last index of larger half
        
        // Fill odd positions with larger elements, even with smaller elements
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                temp[i] = nums[right--];
            } else {
                temp[i] = nums[left--];
            }
        }
        
        // Copy temp back to nums
        for (int k = 0; k < n; k++) {
            nums[k] = temp[k];
        }
    }
}
/*
Difficulty is something like
nlogn time: Medium, (with const space: Medium+)
n time: Hard, (with const space, Hard+)
*/