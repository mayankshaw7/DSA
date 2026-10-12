class Solution {
public:
    bool threeFibonacciSum(int num) {
        int a=0,b=1,c=0;
        vector<int>temp;
        generate(temp,num);
        int n=temp.size();
        for(int i=0;i<n-2;i++){
            if((1LL*temp[i]+temp[i+1]+temp[i+2])==num){
                        return true;
            }
        }
        return false;
    }
    void generate(vector<int>&temp,int num){
          int a=0,b=1,c=0;
            temp.push_back(a);
            temp.push_back(b);
        while(c<=num){
            c=a+b;
           temp.push_back(c);
            a=b;
            b=c;
        }
        // return ;
    }
};