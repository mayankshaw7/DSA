//simple simulation of sliding window 
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int i=0,j=0;
        int maxi=-1;
        while(j<n){
             mp[nums[j]]++;
            while(mp[nums[j]]>k){
               mp[nums[i]]--;
               i++;
            }    
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};