#include <bits\stdc++.h>
using namespace std;
// implementing Adjacency List
// implementing Adjacency List
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
    void BFS_traversal()
    {
        // har ek queue or uska list of negihbor node
        queue<int> q;
        vector<bool> visited(V, false);
        visited[0]=true;
        q.push(0);
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
        DFS_helper(visited, 0);
    }
};
int main()
{
    // Graph g(5);
    // g.addEdges(0, 1);
    // g.addEdges(1, 2);
    // g.addEdges(2, 3);
    // g.addEdges(1, 3);
    // g.addEdges(2, 4);
    // output
    //     0:1
    // 1:0 2 3
    // 2:1 3 4
    // 3:2 1
    // 4:2
        Graph g(7);
    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(3, 4);
    g.addEdges(3, 5);
    g.addEdges(5 ,6);
    g.addEdges(1, 3);
    g.addEdges(2, 4);
    g.addEdges(4,5);
    g.printGraph();
    cout << "Below is BFS traversal : ";
    g.BFS_traversal();
    cout << "\n Below is DFS traversal :";
    g.DFS_traversal();
    return 0;
}