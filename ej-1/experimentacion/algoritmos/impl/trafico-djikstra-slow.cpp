#include <vector>
#include <limits>
using namespace std;


//
// GLOBAL
//

double INF = numeric_limits<double>::infinity();
struct entrada {
    int clave;
    double valor;
};
struct arista {
    int a;
    int b;
    double w; // peso
};

entrada extract_min(vector<entrada>& Q, vector<int>& I) {
    entrada min = Q[0];
    for (int i = 0; i < Q.size(); i++) {
        if (min.valor > Q[i].valor) min = Q[i];
    }
    Q[I[min.clave]] = Q[Q.size()-1]; // Swappeamos el ultimo para extraer
    I[Q[Q.size()-1].clave] = I[min.clave];
    I[min.clave] = -1;
    Q.pop_back();
    return min;
}


vector<double> dijkstra(const vector<vector<arista>>& G, int s) {
    int n = G.size();
    vector<double> D(n, INF); D[s] = 0; // distancias
    vector<entrada> Q(n);
    vector<int> I(n);
    for(int i = 0; i < n; i++) {
        Q[i] = entrada{i, INF};
        I[i] = i;
    }
    Q[s].valor = 0;
    while (!Q.empty()) {
        entrada u = extract_min(Q, I);
        for (const arista& v : G[u.clave])
            if (D[v.b] > D[u.clave] + v.w) {
                D[v.b] = D[u.clave] + v.w;
                if (I[v.b] < Q.size() && I[v.b] >= 0) {
                    Q[I[v.b]].valor = D[v.b]; //decrease_key
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

