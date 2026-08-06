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
void bellmanFord(vector<vector<Edge>>&graph,int V,int src){

    vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        for(int u=0;u<V;u++){
            for(Edge e:graph[u]){
                if(dist[u]!=INT_MAX && dist[e.v]>dist[u]+e.wt){
                     dist[e.v]=dist[u]+e.wt;
                }
            }
        }
    }
     // Step 3: Check for negative-weight cycles
    // If we can still relax an edge after |V| - 1 iterations, then there is a negative cycle
    for(int u=0;u<V;u++){
    for(Edge e : graph[u]){
        if(dist[u] != INT_MAX && dist[u] + e.wt < dist[e.v]){
            cout << "Graph contains negative weight cycle!" << endl;
            cout << "Bellman-Ford algorithm cannot find correct shortest paths." << endl;
            return;
        }
    }
}
    cout << "Vertex\tDistance from Source " << src << endl;
    cout << "--------------------------------" << endl;
    for(int i = 0; i < V; i++){
        if(dist[i] == INT_MAX)
            cout << i << "\t\tUnreachable" << endl;
        else
            cout << i << "\t\t" << dist[i] << endl;
    }
}
int main(){
    int V=5;
    vector<vector<Edge>>graph(V);
     graph[0].push_back(Edge(1,2));
     graph[0].push_back(Edge(2,4));

     graph[1].push_back(Edge(2,-4));
     graph[2].push_back(Edge(3,2));

     graph[3].push_back(Edge(4,4));

     graph[4].push_back(Edge(1,-1));
    // graph[4].push_back(Edge(1,-10)); //replace this line of code for checking the result of negative weught cycle
     bellmanFord(graph,V,4);
     return 0;
 }