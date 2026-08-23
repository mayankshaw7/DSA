class Solution {
    public boolean isPalindromic(String s) {
        int n = s.length();
        if(n==0){
            return false;
        }
        StringBuilder bin = new StringBuilder();
        for (char c : s.toCharArray()) {
            char ch=(char)c;
            for (int j = 7; j >=0; j--) {//runs 8 times constant time 
                bin.append((ch >> j) & 1);
            }
        }

        for(int i=0;i<bin.length()/2;i++){
            if(bin.charAt(i)!=bin.charAt(bin.length()-i-1)){
                return false;
            }
        }
        return true;
    }
}