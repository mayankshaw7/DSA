class Solution {
public:
    bool isFascinating(int n) {
        string val1=to_string(n*2);
        string val2=to_string(n*3);
        string s=to_string(n)+val1+val2;
        set<char>st;
        for(char ch:s){
            if(ch=='0') return false;
            if(st.count(ch)) return false;
            st.insert(ch);
        }
        cout<<st.size();
        return st.size()==9;
    }
};