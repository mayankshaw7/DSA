#include<bits/stdc++.h>
using namespace std;
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        int w = capacity;

        // store ratio and index
        vector<pair<double,int>> ratio(n);
        for(int i = 0; i < n; i++){
            ratio[i] = { (double)val[i] / wt[i], i };//firstly we have done a explicit
            // conversion after than we have performed our logic of getting weigth of each element

            //we can also put one by one 
        }

        // sort by ratio in descending order
        sort(ratio.begin(), ratio.end(), [](pair<double,int> a, pair<double,int> b){
            return a.first > b.first;//lambda comparattor for sorting using custom method
        });

        double ans = 0.0;
        for(int i = 0; i < n; i++){
            int idx = ratio[i].second;
            if(wt[idx] <= w){  
                ans += val[idx];   // take full item
                w -= wt[idx];
            }else{
                ans += ratio[i].first * w; // take fractional part
                w = 0;
            }
        }
        return ans;
    }

int main(){
    vector<int>val={60,100,120};
    vector<int>wt={10,20,30};
    // int n=val.size();
    // vector<pair<double,int>>ratio(n,make_pair(0.0,0));
    //     for(int i=0;i<n;i++){
    //         ratio[i].first=val[i]/wt[i];
    //         ratio[i].second=i;
    //     }
    // for(int i=0;i<n;i++){
    //     cout<<ratio[i].first<<" "<<ratio[i].second<<endl;
    // }
    cout<<fractionalKnapsack(val,wt,50);

    
    return 0;
}