#include<bits/stdc++.h>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices
    vector<int> *adj;

public:

    Graph(int V);  // Constructor
    int *levels;
    // function to add an edge to graph
    void addEdge(int v, int w);
    int BFS(int s, int t);
    // prints BFS traversal from a given source s
    void printGraph();
};

Graph::Graph(int v)
{
    this->V = v;
    adj = new vector<int>[V];
    levels = new int[V];
    //cout << "graph init \n"
    for (int i = 0; i < V; i++)
        levels[i] = -1;
    //cout << "level init \n";
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::printGraph()
{
    for (int v = 0; v < V; v++)
    {
        //cout << "\n Adjacancy list of vertex "
             //<< v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

int Graph::BFS(int s, int t)
{
    vector <bool> visited(V, false);
    vector <int> queue;
    //cout << "BFS" << endl;

    visited[s] = true;
    queue.push_back(s);
    levels[s] = 0;

    int steps = -1;
    while(!queue.empty())
    {
        int v  = queue.front();
        queue.erase(queue.begin());


        //for(int i = 0; i < V; i++)
        //    visited[i] = false;

        for(auto a : adj[v])
        {
            if (!visited[a])
            {
                visited[a] = true;
                queue.push_back(a);
                levels[a] = levels[v] + 1;
                //cout << levels[a] << " " << levels[v] << endl;
                if (a == t)
                {
                    steps = levels[a];
                    return steps;
                }
            }
        }
    }
    return steps;
}

    int main()
    {
        int N;
        int W;
        int D;

        cin >> N >> W >> D;

        vector <pair<int, int>> AtoB(W+1);
        for (int i = 1; i < W + 1; i++)
        {
            cin >> AtoB[i].first >> AtoB[i].second;
        }
        //cout << "loaded: walk\n";

        int Unsearched = -2;
        //int Unreachable = -1;
        //int Itself = 0;

        //int Nposi = 0;

        vector <int> Seq(N + 1);

        for (int i = 1; i < N+1; i++)
            cin >> Seq[i];
        //cout << "loaded: seq\n";

        vector <pair<int, int>> Dxy(D+1);

        for(int i=1; i < D+1; i++)
        {
            cin >> Dxy[i].first
                >> Dxy[i].second;
        }
        //cout << "loaded: swap\n";

        //graph
        int nodes = N + 1;
        Graph g(N+1);
        //cout <<"graph created\n";

        for(int i=1; i < N+1; i++)
        {
            g.levels[i] = Unsearched;
        }

        //populate the graph
        int from;
        int to;

        //by walkway (there are one-way walkways)
        for(int i=1; i < W+1; i++)
        {
            from = AtoB[i].second;
            to  = AtoB[i].first;
            g.addEdge(from, to);
        }

        g.BFS(N, N + 2);
        //cout << "BFS finished\n";

        multiset<pair<int, int>> minutes;
        const int MAX_MINUTES = 200002;
        for (int i = 1; i < N + 1; i++)
        {
            if (g.levels[Seq[i]] == Unsearched)
                g.levels[Seq[i]] = MAX_MINUTES;

            minutes.insert({(i - 1) + g.levels[Seq[i]], Seq[i]}); //walk[s]
            //minutes.insert(make_pair((i - 1) + g.levels[Seq[i]], Seq[i]); //walk[s]
        }

        int counter = 0;
        for(int d = 1; d < D+1; d++)
        {
            int xi = Dxy[d].first, yi = Dxy[d].second;

            minutes.erase({(xi-1) + g.levels[Seq[xi]], Seq[xi]});
            minutes.insert({(yi-1) + g.levels[Seq[xi]], Seq[xi]});
            minutes.erase({(yi-1) + g.levels[Seq[yi]], Seq[yi]});
            minutes.insert({(xi-1) + g.levels[Seq[yi]], Seq[yi]});
            swap(Seq[xi], Seq[yi]);

            auto minTime = minutes.begin();
            cout << minTime->first << '\n';
        }
        return 0;
    }

    /*
        int V = 4;
        Graph g(V);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        int start = 2;
        cout << "Following is Breadth First Traversal "
             << "(starting from vertex " << start << ") \n";
        g.BFS(2);

        cout << endl;
        cout << "Levels, or depths, or steps, or paths of "
             << "each vertex from vertex " << start << ") \n";

        cout << "vertex " <<  "level" <<endl;
        for(int i=0; i<V; i++) {
           cout << i << "    "  <<  g.levels[i] <<endl;
        }
        return 0;
    }
    */

    /*
    Output:

    Following is Breadth First Traversal (starting from vertex 2)
    2 0 3 1
    */
