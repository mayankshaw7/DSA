//Two main changes is here in this code 
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>>ans=new ArrayList<>();
        List<Integer>temp=new ArrayList<>();
    // 1. MUST SORT to easily skip duplicate elements
        Arrays.sort(candidates); 
        backtrack(ans,candidates,target,0,temp,0);
        return ans;
    }
    private static void backtrack(List<List<Integer>>ans,int []c,int k,int s,List<Integer>temp,int idx){
        if(s==k){
            ans.add(new ArrayList<>(temp));
            return;
        }
        
        if(s>k) return;
        for(int i=idx;i<c.length;i++){
            // 3. FIX: Skip duplicate elements at the same decision level
            if (i > idx && c[i] == c[i - 1]) continue;
            temp.add(c[i]);
            backtrack(ans,c,k,s+c[i],temp,i+1);
            temp.remove(temp.size()-1);
        }
    }
}
/*
Time Complexiity of this code 
Why \(O(2^N)\) and not \[N^{k}\]?
The Power of Two Choices: At every single step for each unique element, the backtracking algorithm essentially makes a binary decision: "Do I include this number in my combination, or do I skip it?" Subset Generation: In the worst-case scenario (for example, if all elements are unique and the target is very large), the algorithm explores every possible subset of the array.
 An array of size N has exactly \[2^{N}\] possible subsets. Detailed Complexity BreakdownTime Complexity: \(O(2^N \times K)\)\(O(2^N)\) to explore all possible combinations.The extra K factor (where K is the average length of a combination) comes from the line ans.add(new ArrayList<>(temp)). 
 Copying elements from temp into a new list takes linear time proportional to the length of the list.Sorting the array at the beginning takes \(O(N \log N)\), which is completely dominated by the exponential \(O(2^N)\)
  backtracking step. Space Complexity: O(K) or O(N)The space is determined by the maximum depth of the recursion stack and the size of the temp list, which is at most N if we end up choosing all elements. (Note: This does not count the space required to store the final output ans). 
*/