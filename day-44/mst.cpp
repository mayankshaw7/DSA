#include <bits/stdc++.h> 
using namespace std;

// --- Graph Class for Undirected Graph Representation ---

class Graph {
    int V; // Number of vertices
    list<pair<int, int>>* l; // Adjacency list for graph

public:
    // Constructor 
    Graph(int V) {
        this->V = V;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt)); // This assumes an undirected graph
    }

    void prim_algo(int src) {
        vector<bool> mst_set(V, false); // Track included vertices
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0, src)); // Push source vertex with 0 weight
        int ans = 0; // Total weight of MST

        while (!pq.empty()) {
            int cost = pq.top().first; // Get the minimum weight
            int u = pq.top().second;    // Get the vertex
            pq.pop();                   // Pop the vertex from the queue

            if (mst_set[u]) {
                continue; // If already included in MST, skip
            }

            mst_set[u] = true;          // Include this vertex in MST
            ans += cost;                // Add cost to total weight

            // Loop through neighbors of the vertex
            for (auto& n : l[u]) {
                int v = n.first;       // Neighbor vertex
                int current_wt = n.second; // Weight of the edge
                if (!mst_set[v]) {     // Only push if v is not included in MST
                    pq.push(make_pair(current_wt, v));
                }
            }
        }
        cout << "Required Weight of the MINIMUM SPANNING TREE: " << ans << "\n";
    }
};

int main() {
    // Create graph and add edges
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);
    graph.prim_algo(0); // Perform Prim's algorithm starting from vertex 0
    return 0;
}
