class Solution {
    public int maxDepth(String s) {
        //uisng the line sweep alogrithm we can solve this question
        int cnt=0,maxi=0;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='('){
                cnt++;
                maxi=Math.max(cnt,maxi);
            }else if(s.charAt(i)==')'){
                cnt--;
            }
        }
        return maxi;
    }
}