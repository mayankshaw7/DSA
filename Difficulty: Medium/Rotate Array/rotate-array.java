class Solution {
    //for the company Accenture 
    public void rotateArr(int arr[], int d) {
        // code here
        //did it with my own without taling help of any one 
        int n=arr.length;
        //Brute Force Approach
        // while(d>0){
        //     int temp1=arr[n-1];
        //     arr[n-1]=arr[0];
            
        //     for(int i=n-2;i>=0;i--){
        //         int temp2=arr[i];
        //         arr[i]=temp1;
        //         temp1=temp2;
        //     }
        //     d--;
        // }
        //doing a inplace swapping 
        if(n==0 || n==1) return;
        //initail
        d = d % n; //
        reverse(arr,0,d-1);
        reverse(arr,d,n-1);
        reverse(arr,0,n-1);
    }
        private void reverse(int [] arr,int start,int end){
            while(start<end){
                int temp1=arr[start];
                arr[start]=arr[end];
                arr[end]=temp1;
                start++;
                end--;
            }
        }
        
    
}