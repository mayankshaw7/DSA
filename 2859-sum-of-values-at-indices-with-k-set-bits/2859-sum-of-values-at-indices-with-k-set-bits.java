class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        //brute force works here 
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int temp=i;
            int cnt=0;
            while(temp>0){
            int lastbit=(temp&1);
            if(lastbit==1){
                cnt++;
            }
            temp=temp>>1;
            }
            if(cnt==k){
                res+=nums.get(i);
            }
        }
        return res;
    }
}