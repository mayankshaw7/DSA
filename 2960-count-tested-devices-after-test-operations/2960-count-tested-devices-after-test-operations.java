class Solution {
    public int countTestedDevices(int[] bp) {
        int cnt=0;
        int n=bp.length;
        for(int i=0;i<n;i++){
            int percent=bp[i]-cnt;
            if(percent>0){
                cnt++;
            }
        }
        return cnt;
    }
}