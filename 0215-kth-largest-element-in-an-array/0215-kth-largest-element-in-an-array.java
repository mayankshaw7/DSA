/*
class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer>max_heap=new PriorityQueue<>(Collections.reverseOrder());

        for(int n:nums){
            max_heap.offer(n);
        }
        int val=0;
        for(int i=0;i<k;i++){
             val=max_heap.poll();
        }
        return val;
    }
}
*/
//min heap optimized Approach time o(NLogK)
class Solution {
    public int findKthLargest(int[] nums, int k) {
        // Keep it as a default Min-Heap
        PriorityQueue<Integer> min_heap = new PriorityQueue<>();

        for (int n : nums) {
            min_heap.offer(n);
            // If the heap grows larger than k, kick out the smallest element
            if (min_heap.size() > k) {
                min_heap.poll();//also returns the value back to the integer 
            }
        }
        // The root of the heap is now the kth largest element
        return min_heap.peek();
    }
}
