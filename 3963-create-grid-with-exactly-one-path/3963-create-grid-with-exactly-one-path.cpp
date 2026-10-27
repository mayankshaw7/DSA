class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string>ans;
        
        for(int i=0;i<m;i++){
            if(i!=m-1){
                string temp(n,'#');
                temp[0]='.';
                 ans.push_back(temp);
            }else{
                string temp(n,'.');
                ans.push_back(temp);
            }
        }
        return ans;
    }
};