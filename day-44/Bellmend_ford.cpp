#include<bits/stdc++.h>
using namespace std;

// Class to represent an edge in the graph
class Edge{
public:
    int u;  // Source vertex
    int v;  // Destination vertex
    int wt; // Weight of the edge
    
    // Constructor to initialize edge properties
    Edge(int u, int v, int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;   
    }
};

/*
 * Bellman-Ford Algorithm to find shortest paths from a source vertex
 * Parameters:
 *   src - source vertex
 *   edges - list of all edges in the graph
 *   v - total number of vertices
 */
// void bellmanFord(int src, vector<Edge>& edges, int v){
//     // Step 1: Initialize distances from source to all vertices as INFINITE
//     vector<int> dist(v, INT_MAX);
//     dist[src] = 0;  // Distance from source to itself is always 0

//     // Step 2: Relax all edges |V| - 1 times
//     // A simple shortest path from source to any other vertex can have at most |V| - 1 edges
//     for(int i = 0; i < v-1; i++){
//         // Iterate through all edges in the graph
//         for(Edge e : edges){
//             // Check if we can get a shorter path to vertex v by going through u
//             // Also ensure that u is reachable (dist[e.u] != INT_MAX)
//             if(dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]){
//                 // Update the distance to v with the new shorter distance
//                 dist[e.v] = dist[e.u] + e.wt;
//             }
//         }
//     }
void bellmanFord(int src, vector<Edge>& edges, int v){
    // Step 1: Initialize distances from source to all vertices as INFINITE
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;  // Distance from source to itself is always 0

    // Step 2: Relax all edges |V| - 1 times
    // A simple shortest path from source to any other vertex can have at most |V| - 1 edges
    for(int i = 0; i < v-1; i++){
        // Iterate through all edges in the graph
        for(Edge e : edges){
            // Check if we can get a shorter path to vertex v by going through u
            // Also ensure that u is reachable (dist[e.u] != INT_MAX)
            if(dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]){
                // Update the distance to v with the new shorter distance
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    // If we can still relax an edge after |V| - 1 iterations, then there is a negative cycle
    for(Edge e : edges){
        if(dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]){
            cout << "Graph contains negative weight cycle!" << endl;
            cout << "Bellman-Ford algorithm cannot find correct shortest paths." << endl;
            return;
        }
    }

    // Step 4: Print the shortest distances from source to all vertices
    cout << "Vertex\tDistance from Source " << src << endl;
    cout << "--------------------------------" << endl;
    for(int i = 0; i < v; i++){
        if(dist[i] == INT_MAX)
            cout << i << "\t\tUnreachable" << endl;
        else
            cout << i << "\t\t" << dist[i] << endl;
    }
}

int main(){
    int V = 6;  // Number of vertices in the graph
    
    // Create a list to store all edges of the graph
    vector<Edge> edges;
    
    // Build the graph by adding all edges
    // Format: Edge(source, destination, weight)
    // edges.push_back(Edge(0, 1, 2));  // Edge from vertex 0 to vertex 1 with weight 2
    // edges.push_back(Edge(0, 2, 4));  // Edge from vertex 0 to vertex 2 with weight 4
    // edges.push_back(Edge(1, 2, 1));  // Edge from vertex 1 to vertex 2 with weight 1
    // edges.push_back(Edge(1, 3, 7));  // Edge from vertex 1 to vertex 3 with weight 7
    // edges.push_back(Edge(2, 4, 3));  // Edge from vertex 2 to vertex 4 with weight 3
    // edges.push_back(Edge(3, 5, 1));  // Edge from vertex 3 to vertex 5 with weight 1
    // edges.push_back(Edge(4, 3, 2));  // Edge from vertex 4 to vertex 3 with weight 2
    // edges.push_back(Edge(4, 5, 5));  // Edge from vertex 4 to vertex 5 with weight 5
edges.push_back(Edge(0,1,2));
edges.push_back(Edge(0,2,4));
edges.push_back(Edge(1,2,-4));
edges.push_back(Edge(2,3,2));
edges.push_back(Edge(3,4,4));
edges.push_back(Edge(4,1,-1));
    // Execute Bellman-Ford algorithm with source vertex 0
    cout << "Bellman-Ford Algorithm Results:" << endl;
    cout << "===============================" << endl;
    bellmanFord(0, edges, V);
    
    return 0;
}

/*
 * Example demonstrating Bellman-Ford with negative weights
 * but no negative cycle
 */
// void negativeWeightExample(){
//     cout << "\nExample with Negative Weights (No Cycle):" << endl;
//     cout << "=========================================" << endl;
    
//     int V = 4;
//     vector<Edge> edges;
    
//     // Graph with negative weight but no negative cycle
//     edges.push_back(Edge(0, 1, 4));   // 0 → 1 (weight 4)
//     edges.push_back(Edge(0, 2, 5));   // 0 → 2 (weight 5)
//     edges.push_back(Edge(2, 1, -2));  // 2 → 1 (weight -2) - Negative weight
//     edges.push_back(Edge(1, 3, 1));   // 1 → 3 (weight 1)
    
//     bellmanFord(0, edges, V);
// }

// /*
//  * Example demonstrating negative cycle detection
//  */
// void negativeCycleExample(){
//     cout << "\nExample with Negative Cycle Detection:" << endl;
//     cout << "======================================" << endl;
    
//     int V = 3;
//     vector<Edge> edges;
    
//     // Graph with negative cycle: 0 → 1 → 2 → 0 (total weight: -1)
//     edges.push_back(Edge(0, 1, 1));   // 0 → 1 (weight 1)
//     edges.push_back(Edge(1, 2, -1));  // 1 → 2 (weight -1)
//     edges.push_back(Edge(2, 0, -1));  // 2 → 0 (weight -1) - Creates negative cycle
    
//     bellmanFord(0, edges, V);
// }

// // Uncomment the following lines in main() to test these examples:
// /*
//     negativeWeightExample();
//     negativeCycleExample();
// */
