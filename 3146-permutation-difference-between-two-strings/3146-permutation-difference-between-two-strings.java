class Solution {
    public int findPermutationDifference(String s, String t) {
        int sum=0;
        HashMap<Character,Integer>mp=new HashMap<>();

        // for(char ch:s.toCharArray()){
        //     mp.put(ch,i);
        // }
        for(int i=0;i<s.length();i++){
            mp.put(s.charAt(i),i);
        }
        for(int i=0;i<t.length();i++){
            sum+=Math.abs(mp.get(t.charAt(i))-i);
        }
        return sum;
    }
}