    #include<bits\stdc++.h>
    using namespace std;

    int main(){
        char arr[5]="code";
        int n=sizeof(arr)/sizeof(char);
        n = strlen(arr);
        cout<<n<<endl;
        char arrr[5]={'c','o','d','e','\0'};
        n=sizeof(arrr)/sizeof(char);
        cout<<n<<endl;
        // cout<<arr.size();
        cout<<arr<<" "<<arrr<<endl;
        return 0;
    }