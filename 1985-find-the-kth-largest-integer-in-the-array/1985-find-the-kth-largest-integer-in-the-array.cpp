class Solution {
public:
//Solved using normal Comparator here in 
static bool cmp(string &a, string &b){
    if(a.size()==b.size()){
        return a<b;
    }
    return a.size()<b.size();
}
    string kthLargestNumber(vector<string>& nums, int k) {
        //using the custom sorting here in

        sort(nums.begin(),nums.end(),cmp);
        return nums[nums.size()-k];
    }
};