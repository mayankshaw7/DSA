class Solution {
    public int reverse(int x) {
        
        long ans=0;
        int sign=1;
        if(x<0) sign=-1;
        long temp=x*sign;
        while(temp>0){
            long re=temp%(long)10;
            ans=(ans*10)+re;
            temp/=10;
        }
        long res= ans*sign;
        return (res>Integer.MAX_VALUE ||res<Integer.MIN_VALUE)? 0 :(int)res;
    }
}