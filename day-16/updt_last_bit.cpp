  #include<bits\stdc++.h>
    using namespace std;

    int main(){
        int num,i;
        cout<<"Enter the number : "<<endl;
        cin>>num;
        cout<<"Enter ith last to set to eliminate :";cin>>i;
        num=num& ((~0)<<i); 
        cout<<endl<<num;

        return 0;

    }