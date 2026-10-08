class Solution {
    public String removeOuterParentheses(String s) {
        String ans="";
            int open=0;
        for(char ch:s.toCharArray()){
            if(ch=='('){
                open++;
                if(open>1){
                    ans+=ch;
                }
            }else{
                if(open>1){
                    ans+=ch;
                }
                open--;
            }
        }
        return ans;
    }
}