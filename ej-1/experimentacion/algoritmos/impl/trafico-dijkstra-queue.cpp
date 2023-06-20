#include <vector>
#include <limits>
#include <iostream>
#include <queue>

using namespace std;


//
// GLOBAL
//

double INF = numeric_limits<double>::infinity();
struct arista {
    int a;
    int b;
    double w; // peso
};
struct entrada {
    int clave;
    double valor;
};


//
// DIJKSTRA
//

vector<double> dijkstra(const vector<vector<arista>>& G, int s) {
    int n = G.size();
    vector<double> D(n, INF); D[s] = 0; // distancias
    queue<entrada> q; q.push(entrada{s,0});
    vector<bool> processed(n);
    while (!q.empty()) {
        int v = q.front().clave; q.pop();
        if (processed[v]) continue;
        processed[v] = true;
        for (const arista& u: G[v]) {
            if (D[u.b] > D[v] + u.w) {
                D[u.b] = D[v] + u.w;
                q.push(entrada{u.b, -D[u.b]});
            }
        }
    }
    return D;
}


//
// SOLUCION
//

double resolver(const vector<vector<arista>>& D, const vector<vector<arista>>& T, const vector<arista>& X, int s, int t) {
    vector<double> Ds = dijkstra(D, s);
    vector<double> Tt = dijkstra(T, t);
    double min = Ds[t];
    for (const arista& x : X) {
        if (Ds[x.a] + x.w + Tt[x.b] < min) // s --> a -> b --> t
            min = Ds[x.a] + x.w + Tt[x.b];
        if (Ds[x.b] + x.w + Tt[x.a] < min) // s --> b -> a --> t
            min = Ds[x.b] + x.w + Tt[x.a];
    }
    return min == INF ? -1 : min;
}
