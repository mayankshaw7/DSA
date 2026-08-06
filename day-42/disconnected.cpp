#include <bits\stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        this->V = v;
        // dynamically allocating the list
        l = new list<int>[V];
        // int *arr;
        // arr=new int[V];
    }
    void addEdges(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printGraph()
    {
        for (int u = 0; u < V; u++)
        {
            list<int> neighbors = l[u];
            cout << u << ":";
            for (int v : neighbors)
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
    void BFS_helper(int st,vector<bool>&visited)
    {
        // har ek queue or uska list of negihbor node
        queue<int> q;
        visited[st] = true;
        q.push(st);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cout << u << " ";
            list<int> neighbors = l[u];
            for (int el : neighbors)
            {
                if (!visited[el])
                {
                    visited[el] = true;
                    q.push(el);
                }
            }
        }
    }
    void BFS_traversal(){
         vector<bool> visited(V, false);
         for(int i=0;i<V;i++){
            if(!visited[i]){
                BFS_helper(i,visited);
            }
         }
    }
    //DFS helper funciton for DFS traversal
    void DFS_helper(vector<bool> &visited, int u)
    {
        visited[u] = true;
        cout << u << " ";
        list<int> neighbors = l[u];
        for (int el : neighbors)
        {
            if (!visited[el])
                DFS_helper(visited, el);
        }
    }
    void DFS_traversal()
    {
        vector<bool> visited(V, false);
         for(int i=0;i<V;i++){
            if(!visited[i]){
               DFS_helper(visited, i);
            }
         }
       
    }
};
int main()
{
    Graph g(10);
    g.addEdges(1,6);
    g.addEdges(6,4);
    g.addEdges(4,3);
    g.addEdges(4,9);
    g.addEdges(3,7);
    g.addEdges(3,8);
    g.addEdges(0,2);
    g.addEdges(2, 5);
    g.printGraph();
    cout << "Below is BFS traversal : ";
    g.BFS_traversal();
    cout << "\n Below is DFS traversal :";
    g.DFS_traversal();
    return 0;
}