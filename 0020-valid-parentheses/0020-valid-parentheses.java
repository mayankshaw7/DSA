//coded in java programming language

class Solution {
    public boolean isValid(String s) {
        //space optimized apporahc
     Stack<Character>st=new Stack<>();

     for(int i=0;i<s.length();i++){
        if(st.empty() || s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='['){
            st.push(s.charAt(i));
        }
        else if(!st.isEmpty() && (
            (s.charAt(i)==')'&& st.peek()=='(') || (s.charAt(i)=='}') && st.peek()=='{') || (s.charAt(i)==']' && st.peek()=='[')){
            st.pop();
        }else return false;
     }
     if(!st.isEmpty()) return false;
     return true;
    }
}