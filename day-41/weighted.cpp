#include<bits\stdc++.h>
using namespace std;

class Graph{
    int v;
    list<pair<int,int>> *l;
    public:
    Graph(int v){
        this->v=v;
        l=new list<pair<int,int>> [v];
        // int *arr;
        // arr=new int[V];
    }
    void addEdges(int u,int v,int w){
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }
    void printGraph(){
        for(int u=0;u<v;u++){
            list<pair<int,int>> neighbors=l[u];
            cout<<u<<":";
            for(pair<int,int> v:neighbors){
                cout<<"("<<v.first<<","<<v.second<<")"; 
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(5);
        g.addEdges(0,1,5);
        g.addEdges(1,2,3);
        g.addEdges(2,3,7);
        g.addEdges(1,3,2);
        g.addEdges(2,4,6);
        g.printGraph();
    return 0;
}