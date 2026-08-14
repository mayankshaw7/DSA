//Brute Force Inefficient But one more apporach is there 
/*
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,int>st;
        for(auto &str:words){
            st[str]++;
        }
        int cnt=0;
        for(int len=1;len<=s.size();len++){
                if(st.find(s.substr(0,len))!=st.end()){
                    cnt+=st[s.substr(0,len)];
                }
        }
        return cnt;
    }
};
*/
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int n=s.size(),cnt=0;
        for(auto &word:words){
            if(s.substr(0,word.size())==word){
                cnt++;
            }
        }
        return cnt;
    }
};