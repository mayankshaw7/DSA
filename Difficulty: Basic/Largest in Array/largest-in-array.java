class Solution {
    public static int largest(int[] arr) {
        // code here
        int maxi=-1;
        for(int i=0;i<arr.length;i++){
            maxi=Math.max(maxi,arr[i]);
        }
        return maxi;
    }
}
