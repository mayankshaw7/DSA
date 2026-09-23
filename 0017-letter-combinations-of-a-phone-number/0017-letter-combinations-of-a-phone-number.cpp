//ltitle tricky but vcan be done if concpet is clear of backtacking 
class Solution {
public:
vector<string>res;
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        backtrack(mp,digits,"",0);
        return res;
    }
    void backtrack(unordered_map<char,string>&mp,string digits,string temp,int idx){
        if(digits.size()==idx){
            res.push_back(temp);
            return;
        }
        string str=mp[digits[idx]];
        for(int i=0;i<str.size();i++){
            temp.push_back(str[i]);
            backtrack(mp,digits,temp,idx+1);
            temp.pop_back();
        }
    }
};