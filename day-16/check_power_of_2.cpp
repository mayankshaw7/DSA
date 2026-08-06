  #include<bits\stdc++.h>
    using namespace std;

    int main(){
        int num;
        cout<<"Enter the number to check \n whether the number is power of two :"; cin>>num;
        if(!(num & (num-1)))
            cout<<"TRUE";
        else    cout<<"False";
        return 0;

    }