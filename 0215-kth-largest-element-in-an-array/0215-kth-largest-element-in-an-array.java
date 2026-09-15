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