//brute force approach 
class Solution {
    public int findPeakElement(int[] nums) {
        //There can be multiple peak elements 
        int n=nums.length;
        //edge cases handled 
        //making this code efficient
        if(n>1 && nums[n-1]>nums[n-2]){
            return n-1;
        }

        if(n>1 && nums[0]>nums[1]){
            return 0;
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                return i;
            }
        }
        return 0;
    }
}