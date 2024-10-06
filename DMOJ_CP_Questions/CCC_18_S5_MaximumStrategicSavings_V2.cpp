#include <bits/stdc++.h>

using namespace std;

class ABCost
{
public:
    int a, b, cost;
};

const int MAX = 1e6-1;
int root[MAX];
int nodes, edges;
vector<pair <int, pair<int, int>>> p;
vector<ABCost> selected;

int parent(int a) {
    while(root[a] != a) {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b) {
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

long long kruskal() {
    int a, b;
    long long cost, minCost = 0;
    for(int i = 0 ; i < edges ; ++i) {

        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;
        //cout << parent(a) << " " << parent(b) << endl;
        if(parent(a) != parent(b)) {
            minCost += cost;
            union_find(a, b);
            //cout << "MC " << minCost << endl;
            selected.push_back({a, b, cost});
        }
    }
    return minCost;
}

int main() {
    //int maxToPlanet = -1;
    //int minToPlanet = 1000000000;
    //int maxInPlanet = -1;
    //int minInPlanet = 1000000000;
    int N;
    int M;
    int P;
    int Q;

    cin >> N >> M >> P >> Q;

    vector<ABCost> Pabc;
    vector<ABCost> Qxyz;

    Pabc.resize(P);
    Qxyz.resize(Q);

    long long total = 0;
    int a, b, c;

    //int x, y;
    //long long weight, cost, minCost;
    for(int i = 0; i < P; ++i) {
        cin >> a >> b >> c;
        if(a > b) {
            swap(a, b);
        }
        Pabc[i].a = a-1;
        Pabc[i].b = b-1;
        Pabc[i].cost = c;
    }
    //cout << "Pabc loaded" << endl;

    for(int i = 0; i < Q; i++) {
        cin >> a >> b >> c;
        if(a > b) {
            swap(a, b);
        }
        Qxyz[i].a = a-1;
        Qxyz[i].b = b-1;
        Qxyz[i].cost = c;
    }

    nodes = M;
    edges = P;

    p.resize(edges);
    for(int i = 0; i < nodes; i++) {
        root[i] = i;
    }

    int p_count = 0;
    for(int f = 0; f < P; f++) {

        int eai =Pabc[f].a;
        int ebi =Pabc[f].b;
        int ci = Pabc[f].cost;

        p[p_count] = make_pair(ci, make_pair(eai, ebi));
        //cout << "pcount " << p[p_count].first << endl;
        p_count ++;


        total += (long long)ci*N;

        //if(ci > maxToPlanet) maxInPlanet = ci;
        //if(ci < minToPlanet) minInPlanet = ci;



    }
    sort(p.begin(), p.end());
    //cout << "p " << p.size() << endl;
    long long minCostFlight = kruskal();
    vector<ABCost> selectedFlights(selected);
    //cout << "MCflight " <<minCostFlight << endl;
    nodes = N;
    edges = Q;

    p.clear();
    selected.clear();

    p.resize(edges);
    for(int i = 0; i < nodes; i++) {
        root[i] = i;
    }

    p_count = 0;

    for(int q = 0; q < Q; q++) {
        int xi_f = Qxyz[q].a;
        int yi_f = Qxyz[q].b;
        int zi = Qxyz[q].cost;

        p[p_count] = make_pair(zi, make_pair(xi_f, yi_f));
        p_count ++;
        total += (long long)zi*M;

    }
    //cout << total << endl;
    sort(p.begin(), p.end());
    long long minCostPortal = kruskal();
    vector<ABCost> selectedPortal(selected);
    //cout << "MCportal " << minCostPortal << endl;
    long long newTotal = minCostFlight + minCostPortal;
    if(N == 1) {
        cout << total - minCostFlight << endl;
        return 0;
    }
    int flightOnly = N - 1;
    int i = 0;
    int j = 0;
    bool finished = false;
    while(!finished) {
        if(selectedFlights[i].cost < selectedPortal[j].cost) {
            newTotal += (long long)selectedFlights[i].cost * flightOnly;
            i++;
            if(i == selectedFlights.size())
            {
                finished = true;
            }
        } else {
            int edgeToReplace = M - 1 - i;
            newTotal += (long long)selectedPortal[j].cost * edgeToReplace;
            flightOnly--;
            j++;
            if(j == selectedPortal.size())
            {
                finished = true;
            }
        }

    }

    //cout << "minCost " << minCost << endl;
    //cout << "total " << total << endl;
    cout << total - newTotal << endl;
    return 0;
}
