class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();

        //from left to right
        vector<int>ans(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                ans[i]=ans[i-1]+1;
            }
        }
        //from right to left
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                ans[i]=max(ans[i],ans[i+1]+1);
            }
        }
        int cnt=0;
        for(int it:ans){
            cnt+=it;
        }
        return cnt;
    }
};