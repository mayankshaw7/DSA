//very very easy any one can solve this 
class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        string temp="";
        backtrack(n,0,0,temp);
        return res;
    }
    void backtrack(int n,int open,int close,string &temp){
        if(temp.size()==2*n){
            res.push_back(temp);
            return;
        }

        if(open<n){
            temp.push_back('(');
            backtrack(n,open+1,close,temp);
            temp.pop_back();
        }
        if(close<open){
            temp.push_back(')');
            backtrack(n,open,close+1,temp);
            temp.pop_back();
        }
    }
};