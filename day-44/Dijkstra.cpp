#include<bits\stdc++.h>
using namespace std;

 class Edge{
    public:
    int v;
    int wt;
    Edge(int v,int wt){
        this->v=v;
        this->wt=wt;   
     }
 };
 void dijkstra(int src,vector<vector<Edge>>&graph,int v){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//min heap
     //shorting will be done on the basis of first element,so contain wt at the first element (dist,v )

    //  priority_queue<int,vector<int>,greater<int>>pq;
    //just replace the int with the pair of <int,int>
    vector<int>dist(v,INT_MAX);
    //for containing allthe distance from the src to the each distnation == infinity

    pq.push(make_pair(0,src));
    dist[src]=0;
    while(pq.size()>0){
        int u=pq.top().second;
        pq.pop();
        vector<Edge>edges=graph[u];
        for(Edge e:edges){
            //relaxation step performed here
            if(dist[e.v]>dist[u]+e.wt){
                dist[e.v]=dist[u]+e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }
    for(int d:dist){
        cout<<d<<" "; 
    }
    cout<<endl;

 }

 int main(){
    int V=6;
    vector<vector<Edge>>graph(V);
     graph[0].push_back(Edge(1,2));
     graph[0].push_back(Edge(2,4));

     graph[1].push_back(Edge(2,1));
     graph[1].push_back(Edge(3,7));

     graph[2].push_back(Edge(4,3));

     graph[3].push_back(Edge(5,1));

     graph[4].push_back(Edge(3,2));
     graph[4].push_back(Edge(2,5));
     dijkstra(0,graph,V);
     return 0;
 }