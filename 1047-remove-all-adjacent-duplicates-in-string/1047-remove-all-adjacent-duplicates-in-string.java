//did this with my own got solve in a minutes 
class Solution {
    public String removeDuplicates(String s) {
        Stack<Character> st = new Stack<>();
        int n = s.length();
        for (char ch : s.toCharArray()) {

            if (!st.isEmpty() && st.peek() == ch)
                st.pop();
            else
                st.push(ch);
        }

        StringBuilder res = new StringBuilder();

        while (!st.isEmpty()) {
            res.append(st.peek());
            st.pop();

        }
        return res.reverse().toString();
    }
}