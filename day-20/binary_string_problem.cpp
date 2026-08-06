#include <bits/stdc++.h>
using namespace std;

void binary_string(int n,int lastdigit, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    if(lastdigit !=1){
        binary_string(n-1,0,ans+'0');
        binary_string(n-1,1,ans+'1');
    }else{
        binary_string(n-1,0,ans+'0');
    }
}
void binary_string(int n, string ans)
{
    if (n == 0)
    {
        cout << ans << endl;
        return;
    }
    if(ans[ans.size()-1] !=1){ // this is the second way of doing the job of wihotut using the lastdigit
        binary_string(n-1,ans+'0');
        binary_string(n-1,ans+'1');
    }else{
        binary_string(n-1,ans+'0');
    }
}
int main()
{
    int s;
    string ans;
    cout << "Enter the number to check binary string : ";
    cin >> s;
    binary_string(s,0,ans);
    return 0;
}