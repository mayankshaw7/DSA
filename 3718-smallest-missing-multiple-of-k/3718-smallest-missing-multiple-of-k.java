class Solution {
    public int missingMultiple(int[] nums, int k) {
        HashSet<Integer>mp=new HashSet<>();
        for(int num:nums){
            mp.add(num);
        }
        int i=1;
        while(true){
            if(mp.contains(i*k)){
                i++;
            }else{
                return i*k;
            }
        }
        // return 0;
    }
}