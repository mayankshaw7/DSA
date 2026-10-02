//done very simple approach reverse three times and you are done
class Solution {
    public void rotate(int[] nums, int k) {
        int n=nums.length;
       if(n==0 || n==1) return;
        k=k%n;
        if(k>n){
            return ;
        }

        swap(nums,0,n-1);
        swap(nums,0,k-1);
        swap(nums,k,n-1);
    }
    private static void swap(int [] arr,int i,int j){
        // int i=0,n=arr.length()-1;
        // int j=n-1;

        while(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;j--;
        }
        // return arr;
    }
}