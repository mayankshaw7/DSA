/* Also can be done using the hashset 
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
*/
//Optimized approach
class Solution {
    public int lengthOfLongestSubstring(String s) {
        // Direct array lookup for ASCII characters (size 128)
        int[] lastIndex = new int[128];
        
        // Fill array with -1 (or 0-based offsets)
        java.util.Arrays.fill(lastIndex, -1);
        
        int longest_size = 0;
        int i = 0; // Left boundary of sliding window
        
        for (int j = 0; j < s.length(); j++) {
            char c = s.charAt(j);
            
            // If character was seen before inside current window, move left pointer
            if (lastIndex[c] >= i) {
                i = lastIndex[c] + 1;
            }
            
            lastIndex[c] = j; // Update last seen index
            longest_size = Math.max(longest_size, j - i + 1);
        }
        
        return longest_size;
    }
}
