class Solution {
public:
    int calculateScore(int a, int b) {
        int cnt_1=0;
        int cnt_2=0;
        while(a>0){
            cnt_1+=a&1;
            a=a>>1;
        }
        while(b>0){
              cnt_2+=b&1;
            b=b>>1;
        }
        int ans=0;
        if(cnt_1>=cnt_2){
            ans=cnt_1*cnt_2;
        }else{
            ans=cnt_2/cnt_1;
        }
        return ans;
    }
};