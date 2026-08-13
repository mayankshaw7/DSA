class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // one edge case is coming in mind is this
        int n = arr.size();
        if (n < 3)
            return false;
        // if Contiguous duplicates then also it is invalid array
        // if ele>past and ele<prev then it is valid
        bool increasing = true;
        bool decreasing = true;
        int i=1;
        while (i < n) {
            if (arr[i] == arr[i - 1])
                return false;
            if (arr[i - 1] > arr[i])
                break;
            i++;
        }
        if(i==n) return false;
        if(i==1) return false;
        while (i < n) {
            if (arr[i] == arr[i - 1])
                return false;
            if (arr[i - 1] < arr[i])
                break;
            i++;
        }
        //it means reached end
        if (i == n )
            return true;
        return false;
    }
};