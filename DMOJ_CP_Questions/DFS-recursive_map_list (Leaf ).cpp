/*
Customize by STEM Yard
Mark leaves and branches with certain property

original DFS basic program:
https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

// C++ program to print DFS traversal from
// a given vertex in a  given graph

*/

#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph
{
public:
    int V;
    Graph(int v);

    vector <int> levels; // depths
   vector<bool> special; // the vertex is something different
   vector<bool> special_path; // the vertex is something different

    map<int, bool> visited;
    map<int, list<int>> adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    int DFS(int v, int t);
    void initSpecial(bool spec);
};

Graph::Graph(int v_count)
{
    V = v_count;
    levels.resize(V);
    special.resize(V);
    special_path.resize(V);
}

void Graph::initSpecial(bool spec) {
    for (auto lv : levels)
      lv = -1;

    for (auto s : special)
      s = spec;

    for (auto ns : special_path)
      ns = false;

}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

int Graph::DFS(int v, int t)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";
    int t_level = -1;

    if(v == t) {
       return t_level;
    }

    if(special[v] == true)
         special_path[v] = true;
    else
         special_path[v] = false;

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i, t);
            if(special_path[*i] == true)
               special_path[v] = true;
            levels[*i] = levels[v] + 1;
                cout << endl << "depth " << v << " " << *i << " " << levels[v]<<  " " << levels[*i]<< endl;
            if(*i == t) { // reached target node
                t_level = levels[*i];
                return t_level;
            }
        }

    }
    return t_level;

}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    int V = 8;
    Graph g(V);

    g.initSpecial(false); // set any value
    g.special[5] = true;
    g.special[2] = true;

    // two-way
    g.addEdge(0, 1);
    g.addEdge(1, 0);

    g.addEdge(0, 2);
    g.addEdge(2, 0);

    g.addEdge(2, 3);
    g.addEdge(3, 2);

    g.addEdge(4, 3);
    g.addEdge(3, 4);

    g.addEdge(6, 1);
    g.addEdge(1, 6);

    g.addEdge(1, 5);
    g.addEdge(5, 1);

    g.addEdge(3, 7);
    g.addEdge(7, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 5, one of special vertices) \n";
    g.DFS(5, V + 2);

    int i = 0;
    cout << "\n special\n";
    for (auto s : g.special) {
         cout << i << ' ' << s << '\n';
      i++;
    }

    i = 0;
    cout << "\n special_path\n";
    for (auto ns : g.special_path) {
         cout << i << ' ' << ns << '\n';
      i++;
    }


    i = 0;
    cout << "\n level (depth)\n";
    for (auto lv : g.levels) {
         cout << i << ' ' << lv << '\n';
      i++;
    }

    return 0;
}

/*
2016 S3 Phonomenal Reviews
8 2
5 2      // are Pho (Thai) restaurants, here 5 and 2 are special

0 1
0 2
2 3
4 3
6 1
1 5
7 3

Output:

Following is Depth First Traversal (starting from vertex 2)
2 0 1 9 3
Complexity Analysis:

Time complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V).
Since an extra visited array is needed of size V.
 Handling Disconnected Graph

Solution: This will happen by handling a corner case.
The above code traverses only the vertices reachable from a given source vertex. All the vertices may not be reachable from a given vertex, as in a Disconnected graph. To do a complete DFS traversal of such graphs, run DFS from all unvisited nodes after a DFS.
The recursive function remains the same.
*/
