class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        backtrack(ans,candidates,temp,target,0,0);
        return ans;
    }
    void backtrack(vector<vector<int>>&ans,vector<int>&c,vector<int>&temp,int t,int s,int idx){
        if(t==s){
            ans.push_back(temp);
            return;
        }
        if(s>t) return;
        for(int i=idx;i<c.size();i++){
            if(i>idx && c[i]==c[i-1]) continue;
            temp.push_back(c[i]);
            backtrack(ans,c,temp,t,s+c[i],i+1);
            temp.pop_back();
        }
    }
};