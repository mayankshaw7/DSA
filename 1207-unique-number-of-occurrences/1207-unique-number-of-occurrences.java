//JAVA specific Code 
class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer,Integer>mp=new HashMap<>();

        int n=arr.length;

        for(int i:arr){
            int count=mp.getOrDefault(i,0)+1;
            mp.put(i,count);
        }
        int key=0;
        Set<Integer>st=new HashSet<>();
        for(Map.Entry<Integer,Integer>m:mp.entrySet()){
          if(st.contains(m.getValue())) return false;
          else st.add(m.getValue());
        }
        return true;
    }
}