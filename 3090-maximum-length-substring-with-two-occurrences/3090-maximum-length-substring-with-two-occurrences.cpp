class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.size();
        int maxi=0;
        vector<int>freq(26,0);
        while(j<n){
            freq[s[j]-'a']++;
            while(freq[s[j]-'a']>2){
            freq[s[i]-'a']--;
            i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};