/*
CCC 2018 S5: Maximum Strategic Savings
STEM Yard 2021-07

using Kruskal's Minimum, iterative
instead of Prim's Minimum
CCC2018_s5_MaximumStrategicSavings_01_Kruskal

Minimum Spanning Tree (MST) algorithm.
Using adjacency vector

- keep all index start from 0, instead of 1
-

*/

#include <bits/stdc++.h>

using namespace std;


class ABCost{
public:
   int a, b, cost;
};
// -------------- Kruskal start--------
const int MAX = 1e6-1;
int root[MAX];
int nodes, edges;
vector<pair <int, pair<int, int>> > p; // cost, a, b

int parent(int a)                                                       //find the parent of the given node
{
    while(root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b)      //check if the given two vertices are in the same “union” or not
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

long long kruskal()
{
    int a, b;
    long long cost, minCost = 0;
    for(int i = 0 ; i < edges ; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;
        if(parent(a) != parent(b))  //only select edge if it does not create a cycle (ie the two nodes forming it have different root nodes)
        {
            minCost += cost;
            union_find(a, b);
        }
    }
    return minCost;
}
// -------------- Kruskal end--------

int main()
{
  int N; // planets
  int M; // cities on each planet
  int P; // N x P two-way flights in the galaxy (one same planets), (e; ai) and (e; bi), cost ci
  int Q; // M x Q two-way portals in the galaxy (between planets), (xj ; f) and (yj ; f) and costs zj

  cin >> N >> M >> P >> Q;
cout << "N=" << N << " M=" << M << " P=" << P << " Q=" << Q << endl;

  //int Pabc[P][3]; // crash when P == 100000
  //int Qxyz[Q][3]; // crash when Q == 100000

  //vector<ABCost> *Pabc = new vector<ABCost>[P]; // error: 'class std::vector<ABCost>' has no member named 'a'; did you mean 'at'?
  //vector<ABCost> *Qxyz = new vector<ABCost>[Q];

  vector<ABCost> Pabc;
  vector<ABCost> Qxyz;

  Pabc.resize(P);
  Qxyz.resize(Q);

  //int mat[100000L*100000L][100000L*100000L];
  //cout << "100000*100000";
  long long total = 0;
  int a, b, c;
  for (int i=0; i < P; i++) {
     cin >> a >> b >> c;
     Pabc[i].a = a - 1;  Pabc[i].b = b - 1;  Pabc[i].cost = c;
  }
    cout << "Pabc loaded" << endl;

  for (int i=0; i < Q; i++)  {
     cin >> a >> b >> c;
     Qxyz[i].a = a - 1;  Qxyz[i].b = b - 1;  Qxyz[i].cost = c;
  }
    cout << "Qxyz loaded" << endl;

    int V = N * M;
    int num_nodes = V; // Nodes (0, 1, ..., N)

    cout << "V=" << V << endl;

    nodes = N * M;
    edges = N * P + M * Q;
    cout << "nodes=" << nodes  << ", edges=" << edges << endl;
    //p = new pair <int, pair<int, int>>[edges];
    p.resize(edges);
    for(int i = 0;i < edges; ++i)  //initialize the array groups
    {
        root[i] = i;   // root is each node itself
    }

    //vector<VPII> graph;
    //graph.resize(num_nodes);

    // add edges with costs to the graph.
    // two-way, undirected graph

    // N * P two-way flights in the galaxy
cout << "N * P=" << N * P << endl;
int maxInPlanet = -1;
int minInPlanet = 1000000000;
int sameCity = 0;

int p_count = 0;
    for (int f=0; f < P; f++) { // for each flight
       for (int e=0; e < N; e++) { //
          int eai = e * M + (Pabc[f].a);
          int ebi = e * M + (Pabc[f].b);
          int ci  = Pabc[f].cost;

          // how about same city to same city (inside a city) ?
          p[p_count] = make_pair(ci, make_pair(eai, ebi));
          p_count ++;

          total += ci;
          if(N < 20)
            cout << eai << ","  << ebi << "," << ci << endl;

       }
    }

    // M * Q two-way portals in the galaxy
int maxToPlanet = -1;
int minToPlanet = 1000000000;

cout << "M * Q=" << M * Q << endl;
for (int q=0; q < Q; q++) {
    for (int f=0; f < M; f++) {
          int xi_f = (Qxyz[q].a) * M + f;
          int yi_f = (Qxyz[q].b) * M + f;
          int zi   = Qxyz[q].cost;

          p[p_count] = make_pair(zi, make_pair(xi_f, yi_f));
          p_count ++;

          total += zi;

          if(N < 20)
            cout << xi_f << "," << yi_f << ","  << zi << endl;
       }
    }
// only for testing ========= start =================
 if(p_count < 20)
    for (int i=0; i < p_count; i++)
       cout << "i =" << i << ", a =" << p[i].second.first << ", b =" << p[i].second.second << ", c =" << p[i].first << endl;

    cout << " root: "<< endl;
int endprint = nodes > 200 ? 200: nodes;

    for (int i=0; i < endprint; i++)
       cout << "i =" << i << ", root =" << root[i] << endl;

    cout << "sameCity=" << sameCity << endl;
    cout << "maxInPlanet=" << maxInPlanet << ", minInPlanet=" << minInPlanet << endl;
    cout << "maxToPlanet=" << maxToPlanet << ", minToPlanet=" << minToPlanet << endl;


    cout << "total= " << total << endl;
if(N > 200) {
  cout << "Too many nodes" << endl;
  return 0;

}
//only for testing ========= end =================

    sort(p.begin() , p.end());  //sort the array of edges
    long long mst_cost = kruskal();

 for (int i=0; i < endprint; i++)
       cout << "i =" << i << ", root =" << root[i] << endl;

    long long saved = total - mst_cost;

    cout << mst_cost << endl;
    cout << saved << endl;

    return 0;
}

/*
Sample Input 1
2 2 1 2
1 2 1
2 1 1
2 1 1

Output for Sample Input 1
3
===========================================
Sample Input 2
2 3 4 1
2 3 5
3 2 7
1 2 6
1 1 8
2 1 5

Output for Sample Input 2
41

Explanation for Output for Sample Input 2
One possible way is to shut down the flights between cities (1; 1) and (1; 1), (2; 1) and (2; 1), (1; 1)
and (1; 2), (1; 3) and (1; 2), (2; 3) and (2; 2), and shut down the portal between cities (2; 3) and
(1; 3) for total energy savings of 8 + 8 + 6 + 7 + 7 + 5 = 41.
===========================================
s5.2-05.in
1729407584886
===========================================
s5.3-01.in                5 sec (N=188 M=75 P=11111 Q=22222)
187102662346090
===========================================
s5.4-05.in              TLE
667719320985806289
*/
