#include<bits\stdc++.h> // Includes most standard library headers (often used in competitive programming)
using namespace std;

// --- Graph Class for Undirected Graph Representation ---
class Graph {
    int V;             // Number of vertices
    list<int>* l;      // Adjacency list (array of lists) for graph
public:
    // Constructor
    Graph(int V) {
        this->V = V;
        // Dynamically allocate an array of V lists
        l = new list<int>[V];
    }
    
    // Function to add an undirected edge between u and v
    void addEdges(int u, int v) {
        l[u].push_back(v); // Edge u -> v
        l[v].push_back(u); // Edge v -> u (since it's an undirected graph)
    }

    /*
     * Cycle detection using DFS in an Undirected Graph.
     * The 'parent' parameter is crucial here.
     * A cycle exists if we encounter a visited neighbor 'v' that is NOT the 'parent' of 'src'.
     */
    bool Cycle_detection(vector<bool>& visited, int src, int parent) {
        // Mark the current node as visited
        visited[src] = true;
        
        list<int> neighbors = l[src]; // Get all neighbors of the current node

        // Recur for all neighbors
        for (int v : neighbors) {
            // Case 1: Neighbor 'v' has not been visited yet
            if (!visited[v]) {
                // Explore the neighbor; if a cycle is found down this path, immediately return true
                if (Cycle_detection(visited, v, src)) {
                    return true;
                }
            } 
            // Case 2: Neighbor 'v' has been visited AND is NOT the parent of 'src'
            // This condition identifies a back-edge that is not the trivial edge back to the parent,
            // thus indicating a cycle (e.g., a triangle).
            else if (v != parent) { 
                return true; // Cycle detected
            }
        }
        // No cycle found starting from this node in the current path
        return false;
    }

    // Clean up memory
    ~Graph() {
        delete[] l;
    }
};

// --- Main function to check for cycle across all components ---
bool isCycle(int V, vector<vector<int>>& edges) {
    // visited: keeps track of all nodes visited across all DFS calls
    vector<bool> visited(V, false);
    
    // 1. Build the graph
    Graph g(V);
    for (int i = 0; i < edges.size(); i++) {
        // edges[i][0] -> u, edges[i][1] -> v
        g.addEdges(edges[i][0], edges[i][1]);
    }
    
    // 2. Iterate through all vertices to handle disconnected components
    for (int i = 0; i < V; i++) { 
        // Only start DFS from an unvisited node
        if (!visited[i]) {
            // Start DFS with current node 'i' and initial parent as -1 (or any invalid index)
            if (g.Cycle_detection(visited, i, -1)) {
                return true; // Cycle found in one component
            }
        }
    }
    
    // No cycle found in any component
    return false;
}

// --- Main execution ---
int main(){
    int Vertex;
    cout<<"Enter number of vertex: ";
    cin>>Vertex; // User input for number of vertices V
    
    // The commented-out input section would allow for dynamic user input of edges
    // cout<<"Enter Number of Edges:";
    // int edge;
    // cin>>edge;
    // vector<vector<int>>edges;
    // for(int i=0;i<edge;i++){
    //     cout<<"Enter the "<<i+1<<"th edge :";
    //     cout<<"start :"<<st<<endl<<"end"<<ed;
    // }

    // Example: A graph with edges {{0,1}, {0,2}, {1,2}, {2,3}}. 
    // This creates a cycle (0-1-2-0) and an extra edge to 3.
    vector<vector<int>>edges={{0,1},{0,2},{1,2},{2,3}}; 
    
    // Check if a cycle exists
    if(isCycle(Vertex,edges)){
        cout<<"CYCLE Exist" << endl;
    }else{
        cout<<"CYCLE NOT EXIST" << endl;
    }
    
    return 0;
}