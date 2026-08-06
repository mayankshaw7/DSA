#include <bits\stdc++.h> // Includes most standard library headers (often used in competitive programming)
using namespace std;

// --- Graph Class for Directed Graph Representation ---

class Graph
{
    int V;        // Number of vertices
    list<int> *l; // Adjacency list (array of lists) for graph
public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        // Dynamically allocate an array of V lists
        l = new list<int>[V];
    }

    // Function to add a directed edge from u to v
    void addEdges(int u, int v)
    {
        l[u].push_back(v); // Directed edge
    }

    /*
     * Cycle detection using DFS in a Directed Graph.
     * The 'recursion_path' array is crucial for directed graphs.
     * A cycle exists if we encounter a visited node that is *also* in the current recursion path.
     */
    void topo_sort_helper(vector<bool> &visited, stack<int> &st, int src)
    {
        // Mark the current node as visited for the overall traversal
        visited[src] = true;

        list<int> neighbors = l[src]; // Get all neighbors of the current node

        // Recur for all neighbors
        for (int v : neighbors)
        {
            // Case 1: Neighbor 'v' has not been visited yet
            if (!visited[v])
            {
                // Explore the neighbor; if a cycle is found down this path, immediately return true
                topo_sort_helper(visited, st, v);
            }
        }
        // Backtrack: Remove the current node from the recursion path
        st.push(src);
}

// Clean up memory
~Graph()
{
    delete[] l;
}
}
;

// --- Solution Class (typically for LeetCode/GFG format) ---
class Solution
{
public:
    /*
     * Main function to check if the entire directed graph contains a cycle.
     */
    void topo_sort(int V, vector<vector<int>> &edges)
    {
        // visited: keeps track of all nodes visited across all DFS calls
        vector<bool> visited(V, false);
        stack<int> st;

        // 1. Build the graph
        Graph g(V);
        for (int i = 0; i < edges.size(); i++)
        {
            // edges[i][0] -> u, edges[i][1] -> v
            g.addEdges(edges[i][0], edges[i][1]);
        }

        // 2. Iterate through all vertices to handle disconnected components
        for (int i = 0; i < V; i++)
        {
            // Only start DFS from an unvisited node
            if (!visited[i])
            {
                g.topo_sort_helper(visited, st, i);
            }
        }
        while (!st.empty())
        {
          cout<<st.top()<<" ";
          st.pop();
        }
        
    }
};

// --- Main execution ---
int main()
{
    int Vertex;
    cout << "Enter number of vertices: ";
    cin >> Vertex; // User input for number of vertices V

    Solution s;

    // Example: A simple linear graph 0 -> 1 -> 2 -> 3 (NO cycle)
    // If you wanted a cycle, you could add: {{0,1},{1,2},{2,3},{3,1}}
    vector<vector<int>> edges = {{5, 0}, {5, 2}, {3, 1}, {2, 3},{4,1},{4,0}};

    // Check if a cycle exists
    s.topo_sort(Vertex, edges);
    return 0;
}