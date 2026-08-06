//basically this program is for the update the bits
#include <bits\stdc++.h>
using namespace std;
void update_the_bit(int num,int i,int val){
  num=num & (~(1<<i));
  num=num | (val<<i);
  cout<<num<<endl;
}

int main()
{
  update_the_bit(7,2,0);
  update_the_bit(7,3,1);
  return 0;
}