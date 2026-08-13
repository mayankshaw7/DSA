class Solution {
public:
    int minIncrementForUnique(vector<int>& arr) {
        //minimum can only be done using greedy solution
        sort(arr.begin(),arr.end());
        int n=arr.size();
        //edge case 1
        if(n==0 ||n==1) return 0;
        int ops=0;
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                int ele=arr[i-1];
                while(arr[i]!=(ele+1)){
                    arr[i]=arr[i]+1;
                    ops++;
                }
            }
        }
        return ops;
    }
};