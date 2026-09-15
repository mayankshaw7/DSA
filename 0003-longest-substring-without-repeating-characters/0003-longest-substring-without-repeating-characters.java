class Solution {
    public int lengthOfLongestSubstring(String s) {
        //using the sliiding window + haspmap
        Map<Character,Integer>mp=new HashMap<>();
        int n=s.length();
        int j=0,i=0;
        int longest_size=0;
        char[] str=s.toCharArray();
        while(j<n){
            mp.put(str[j],mp.getOrDefault(str[j],0)+1);
            while(mp.get(str[j])>1){
                mp.put(str[i],mp.get(str[i])-1);
                i++;
            }
            if(j-i+1>longest_size){
                longest_size=j-i+1;
            }
            j++;
        }
        return longest_size;
    }
}