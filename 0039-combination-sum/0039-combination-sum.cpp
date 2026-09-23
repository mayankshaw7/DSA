//very easy question my friend anyone can do it easily hahahaha what a pattern
class Solution {
public:
vector<vector<int>>res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        backtrack(candidates,temp,target,0,0);
        return res;
    }
    void backtrack(vector<int>&c,vector<int>&temp,int k,int sum,int st){
        if(sum==k){
            res.push_back(temp);
            return;
        }else if(sum>k){
            return;
        }
        for(int i=st;i<c.size();i++){
            temp.push_back(c[i]);
            backtrack(c,temp,k,sum+c[i],i);
            temp.pop_back();
            // sum-=c[i];
        }
    }
};