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
    void all_path(vector<bool> &visited, string &path, int src, int dest)
    {
        if (src == dest)
        {
            cout << path << dest<<endl;
            return;
        }
        // Mark the current node as visited for the overall traversal
        visited[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src]; // Get all neighbors of the current node

        // Recur for all neighbors
        for (int v : neighbors)
        {
            // Case 1: Neighbor 'v' has not been visited yet
            if (!visited[v])
            {
                // Explore the neighbor; if a cycle is found down this path, immediately return true
                all_path(visited, path, v, dest);
            }
        }
        path = path.substr(0, path.size() - 1);
        // Backtrack: Remove the current node from the visted
        // It's crucial to unset this flag *before* returning from the function call for 'src'.
        visited[src] = false;
    }

    // Clean up memory
    ~Graph()
    {
        delete[] l;
    }
};
void path_helper(int V, vector<vector<int>> &edges)
{
    // visited: keeps track of all nodes visited across all DFS calls
    vector<bool> visited(V, false);
    // recursion_path: keeps track of nodes currently in the recursion stack
    string path = "";

    // 1. Build the graph
    Graph g(V);
    for (int i = 0; i < edges.size(); i++)
    {
        // edges[i][0] -> u, edges[i][1] -> v
        g.addEdges(edges[i][0], edges[i][1]);
    }
    g.all_path(visited, path, 5, 1);
}

// --- Main execution ---
int main()
{
    int Vertex;
    cout << "Enter number of vertices: ";
    cin >> Vertex; // User input for number of vertices 
    // Example: A simple linear graph 0 -> 1 -> 2 -> 3 (NO cycle)
    // If you wanted a cycle, you could add: {{0,1},{1,2},{2,3},{3,1}}
    vector<vector<int>> edges = {{5,0}, {5,2}, {2,3}, {3,1},{0,3},{4,1},{4,0}};
    path_helper(Vertex, edges);
    return 0;
}