class Solution {
    public int[] rearrangeArray(int[] nums) {
        Map<Integer, Integer> mp = new TreeMap<>();

        for (int i : nums) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        int[] ans = new int[nums.length];
        int idx = 0;
        while (!mp.isEmpty()) {
            List<Integer> to_remove = new ArrayList<>();
            for (Map.Entry<Integer, Integer> m : mp.entrySet()) {
                int val = m.getKey();
                int freq = m.getValue();
                ans[idx] = val;
                idx++;
                // freq--;
                if (freq == 1) {
                    //  mp.remove(m.getKey());
                    to_remove.add(val);
                } 
                // else {
                //     mp.put(val, freq - 1);
                // }
            }
            //Problem Concurrent operation is not possible man
            //now update element
            for(Map.Entry<Integer, Integer> m : mp.entrySet()){
                int val = m.getKey();
                int freq = m.getValue();
                mp.put(val,freq-1);
            }

            //remove all those element from here 
            for (int i : to_remove)
                mp.remove(i);
        }
        return ans;
    }
}
/*
//Optimized SOlution
import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] freq = new int[101];
        int maxFreq = 0;

        for (int x : nums) {
            freq[x]++;
            if (freq[x] > maxFreq) {
                maxFreq = freq[x];
            }
        }

        int[] ans = new int[nums.length];
        int idx = 0;

        for (int round = 0; round < maxFreq; round++) {
            for (int val = 1; val <= 100; val++) {
                if (freq[val] > 0) {
                    ans[idx++] = val;
                    freq[val]--;
                }
            }
        }

        return ans;
    }
}
*/