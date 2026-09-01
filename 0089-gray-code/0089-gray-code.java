//using the bitmanipulation this can be done easily
//step to solve this using the bitmanipulation
//that is observe the pattern then try to make that pattern you are done with this that is all about this question
//pseudocode
/*
Function grayCode(n):
    result = []
    totalNumbers = 1 << n  // 2^n elements
    
    For i = 0 to totalNumbers - 1:
        // Bitwise XOR between i and (i shifted right by 1)
        grayVal = i XOR (i >> 1)
        add grayVal to result
        
    Return result
    */ 
class Solution {
    public List<Integer> grayCode(int n) {
        int m=1<<n;
        List<Integer>l=new ArrayList<>();
        // l.add(0);
        for(int i=0;i<m;i++){
         int val=i^(i>>1);
         l.add(val);
        }return l;
    }
}