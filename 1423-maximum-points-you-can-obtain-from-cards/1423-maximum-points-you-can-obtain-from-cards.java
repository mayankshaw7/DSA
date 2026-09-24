//Yes it is very easy problem any one can do it 
//if they think in a calm manner 
//aappraooch sliding window + 2 pointers 
//my logivc worked here
/*
was only able to pass 2 test cases which i not suppose to do 
After watching striver's approach now my mind say wow
actually we need to maintain the sun from both the sides as well not only from single side 
*/
class Solution{
    public int maxScore(int [] cp,int k){
        int n=cp.length;
          int currsum=0;
            for(int i=0;i<k;i++){
                currsum+=cp[i];
            }
        int maxisum=currsum;
        for(int i=0;i<k;i++){
            //ciritical section was this 
            currsum-=cp[k-i-1];
            currsum+=cp[n-i-1];
            maxisum=Math.max(maxisum,currsum);
        }
        return maxisum;
    }
}
// class Solution {
//     public int maxScore(int[] cp, int k) {
//         int n=cp.length;
//         int currsum=0;
//         for(int i:cp){
//             currsum+=i;
//         }
//         if(k==n) return currsum;
//         int front=0,last=0;
//         for(int i=0;i<n-k;i++){
//             //choose to remove from front
//             front+=cp[i];
//         }
//         for(int i=n-1;i>k-1;i--)
//             last+=cp[i];
//         int maxisum=0;
//         return Math.max(currsum-front,currsum-last);
//     }
// }
// use ful test case
// [100,40,17,9,73,75]
// 248