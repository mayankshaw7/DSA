/*
$O(n)$ Solution (Optimal)Instead of simulating the process step-by-step from left to right, iterate from right to left.The moment you encounter the first duplicate from the right, it means all elements up to index i must be removed. Since each operation removes 3 elements from the front, the number of operations needed is simply $\lfloor i / 3 \rfloor + 1$.
*/
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        HashSet<Integer>st=new HashSet<>();

        for(int i=n-1;i>=0;i--){
            if(st.contains(nums[i])){
                return (i/3)+1;
            }
            st.add(nums[i]);
        }
        return 0;
    }
};
/*
//brute force Java
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
            int j = 0;
            int ops=0;
        while (j < n) {
            HashMap<Integer, Integer> mp = new HashMap<>();
            boolean remove = false;
            for (int i = j; i < n; i++) {
                if (mp.containsKey(nums[i])) {
                    remove = true;
                    break;
                } else {
                    mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
                }
            }
            if (remove) {
                j += 3;
                ops++;
            } else {
                break;
            }
        }
        return ops;
    }
}
*/