class Solution {
    public boolean checkDivisibility(int n) {
        int temp=n;
        long sum=0,prod=1;
        while(temp>0){
            int rem=temp%10;
            sum+=rem;
            prod*=rem;
            temp/=10;
        }
        long both=sum+prod;
        if(n%both==0) return true;
        return false;
    }
}