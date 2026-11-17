///An optimized way to do it using the tries 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1){
            return strs[0];
        }
        sort(begin(strs),end(strs));
        string first=strs[0];
        string second=strs[strs.size()-1];
        int s1=first.size();
        int s2=second.size();
        int n=min(s1,s2);
        string ans="";
        for(int i=0;i<n;i++){
            if(first[i]!=second[i]){
                return ans;
            }else{
                ans+=first[i];
            }
        }
        return ans;
    }
};