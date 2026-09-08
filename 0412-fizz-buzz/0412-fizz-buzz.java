class Solution {
    public List<String> fizzBuzz(int n) {
        String s1 = "FizzBuzz";
        String s2 = "Fizz";
        String s3 = "Buzz";
        List<String> ans = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                ans.add(s1);
            } else if (i % 3 == 0) {
                ans.add(s2);
            } else if (i % 5 == 0) {
                ans.add(s3);
            } else {
                ans.add(Integer.toString(i));
            }
        }
        return ans;
    }
}