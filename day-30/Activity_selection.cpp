#include<bits/stdc++.h>
using namespace std;

int main(){
// vector<pair<int,int>>act={{20,30},{12,15},{10,20}};
vector<pair<int,int>>act={{3,4},{2,3},{1,2},{1,3}};
sort(act.begin(),act.end(), [](pair<int,int>a,pair<int,int> b){
    return b.second>a.second;
});
for(int i=0;i<act.size();i++){
    cout<<act[i].first<<" "<<act[i].second<<endl;
}
int take=1;
int end=act[0].second;
for(int i=1;i<act.size();i++){
    if(act[i].first >=end){
        take++;
         end=act[i].second;
    }
   
}
cout<<"Total number of activity performed here is : "<<take;
    return 0;
}