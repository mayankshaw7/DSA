//coded by self with out any help borthere 
class Solution {
    public List<String> generateParenthesis(int n) {
        StringBuilder temp=new StringBuilder();
        List<String> str=new ArrayList<>();
        backtrack(str,n,0,0,temp);

        return str;
    }
    private static void backtrack(List<String>str,int n,int open,int close,StringBuilder temp){
        if(temp.length()==n*2){
            str.add(temp.toString());
            return;

        }
        if(open<n){
            temp.append('(');
            backtrack(str,n,open+1,close,temp);
            temp.deleteCharAt(temp.length()-1);
        }
        if(close<open){
            temp.append(')');
            backtrack(str,n,open,close+1,temp);
            temp.deleteCharAt(temp.length()-1);
        }
    }
}