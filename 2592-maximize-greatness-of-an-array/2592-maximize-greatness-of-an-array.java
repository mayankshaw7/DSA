//Approach Greedy asked in many OA rounds OPs
/*
Correct Approach (Two Pointers / Greedy)
Sort nums in ascending order.

Maintain a pointer i (representing elements to be beaten) and a pointer j (representing elements in the permutation trying to beat them).

Whenever nums[j] > nums[i], increment i (you matched one pair) and always increment j.

The final value of i will be your answer.
*/
class Solution {
    public int maximizeGreatness(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        for (int x : nums) {
            if (x > nums[i]) {
                i++;
            }
        }
        return i;
    }
}

/* only passed 430 test cases 
class Solution {
    public int maximizeGreatness(int[] nums) {
        //only need to count the greater element after each elements so 
        //which makes it very question for this time being
        //stretegy i will maintain the maximum element from the back 
        //and accordingly i will count the element
        int n=nums.length;
        int cnt=0;
        int maxi=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<maxi){
                cnt++;
            }else{
                maxi=nums[i];
            }
        }
        return cnt;
    }
}
*/
