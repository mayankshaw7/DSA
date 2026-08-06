#include<bits/stdc++.h>
using namespace std;

char nonRepeatingChar(string &s) {
        queue<char> q;
        int freq[26] = {0};
        
        for(char ch : s) {
            freq[ch - 'a']++;
            q.push(ch);
        }
        
        while(!q.empty() && freq[q.front()-'a'] > 1) {
            q.pop();
        }
        
        return q.empty() ? '$' : q.front();
    }

int main(){
    string s="aaabbccx";
    cout<<"The non repeating character here is "<<nonRepeatingChar(s);
    return 0;
}