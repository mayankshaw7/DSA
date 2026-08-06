#include <bits\stdc++.h>
using namespace std;
void count_set_bit(int num){
    int count=0;
    while(num>0){
        int last_digit=num&1;
        count+=last_digit;
       num= num>>1;
    }
    cout<<count;
    
}
int main()
{   cout<<"Enter number of present in it is : ";
    count_set_bit(15);
    return 0;
}