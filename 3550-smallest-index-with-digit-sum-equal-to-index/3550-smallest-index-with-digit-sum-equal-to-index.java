class Solution {
    public int smallestIndex(int[] nums) {
        int small=-1;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(digitsum(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
    private static int digitsum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
}