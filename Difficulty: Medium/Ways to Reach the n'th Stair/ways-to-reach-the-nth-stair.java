class Solution {
    public int countWays(int n) {
        // code here
        //using the fico nagi series in order to do this 
        //recursive solution to this problem 
        if(n==1 || n==0) return n;
        int t1=0,t2=1;
        int t3=0;
        for(int i=1;i<=n;i++){
            t3=t1+t2;
            t1=t2;
            t2=t3;
        }
        return t3;
    }
}