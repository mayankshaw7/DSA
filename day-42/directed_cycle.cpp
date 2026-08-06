#include<bits\stdc++.h> // Includes most standard library headers (often used in competitive programming)
using namespace std;


// --- Graph Class for Directed Graph Representation ---

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
    
    // Function to add a directed edge from u to v
    void addEdges(int u, int v) {
        l[u].push_back(v); // Directed edge
    }

    /*
     * Cycle detection using DFS in a Directed Graph.
     * The 'recursion_path' array is crucial for directed graphs.
     * A cycle exists if we encounter a visited node that is *also* in the current recursion path.
     */
    bool Cycle_detection(vector<bool>& visited, vector<bool>& recursion_path, int src) {
        // Mark the current node as visited for the overall traversal
        visited[src] = true;
        // Mark the current node as part of the current recursion stack (DFS path)
        recursion_path[src] = true;

        list<int> neighbors = l[src]; // Get all neighbors of the current node

        // Recur for all neighbors
        for (int v : neighbors) {
            // Case 1: Neighbor 'v' has not been visited yet
            if (!visited[v]) {
                // Explore the neighbor; if a cycle is found down this path, immediately return true
                if (Cycle_detection(visited, recursion_path, v)) {
                    return true;
                }
            } 
            // Case 2: Neighbor 'v' has been visited AND is currently in the recursion path
            // This condition is true ONLY for a back-edge in a directed graph, indicating a cycle.
            else if (recursion_path[v]) {
                return true; // Cycle detected
            }
        }

        // Backtrack: Remove the current node from the recursion path
        // It's crucial to unset this flag *before* returning from the function call for 'src'.
        recursion_path[src] = false;
        
        // No cycle found starting from this node in the current path
        return false;
    }
    
    // Clean up memory
    ~Graph() {
        delete[] l;
    }
};

// --- Solution Class (typically for LeetCode/GFG format) ---
class Solution {
 public:
    /*
     * Main function to check if the entire directed graph contains a cycle.
     */
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // visited: keeps track of all nodes visited across all DFS calls
        vector<bool> visited(V, false);
        // recursion_path: keeps track of nodes currently in the recursion stack
        vector<bool> recursion_path(V, false);
        
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
                // The parent parameter is generally not needed for directed graph cycle detection
                // but we keep it and pass -1 as per the original code's signature.
                if (g.Cycle_detection(visited, recursion_path, i)) {
                    return true; // Cycle found in one component
                }
            }
        }
        
        // No cycle found in any component
        return false;
    }
};

// --- Main execution ---
int main(){
    int Vertex;
    cout << "Enter number of vertices: ";
    cin >> Vertex; // User input for number of vertices V
    
    Solution s;
    
    // Example: A simple linear graph 0 -> 1 -> 2 -> 3 (NO cycle)
    // If you wanted a cycle, you could add: {{0,1},{1,2},{2,3},{3,1}}
    vector<vector<int>> edges = {{0,1}, {1,2}, {3,3},{2,3}}; 
    
    // Check if a cycle exists
    if(s.isCyclic(Vertex, edges)){
        cout << "CYCLE Exist" << endl;
    } else {
        cout << "CYCLE NOT EXIST" << endl;
    }
    return 0;
}