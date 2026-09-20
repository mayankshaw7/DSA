class Solution {
    public int reverseDegree(String s) {
        int n=s.length();
        int sum=0;

        for(int i=0;i<n;i++){
            char ch=s.charAt(i);
            // System.out.println(Integer.valueOf(ch)-'a'+1);
            int idx=Math.abs(ch-'a');
            // System.out.println(26-idx);
                        
            sum=sum+(26-idx)*(1+i);
        }
        return sum;
    }
}