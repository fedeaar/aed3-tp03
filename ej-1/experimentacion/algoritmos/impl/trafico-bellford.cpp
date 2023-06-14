#include <vector>
#include <limits>
#include <iostream>
using namespace std;

double INF = numeric_limits<double>::infinity();
struct arista {
    int a;
    int b;
    double w; // peso
};


vector<double> bellford(const vector<vector<arista>>& G, int s) {
    int n = G.size();
    vector<double> D(n, INF); D[s] = 0; // distancias
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (const arista& v : G[i]) {
                if (D[v.b] > D[v.a] + v.w) {
                    D[v.b] = D[v.a] + v.w;
                }
            }
        }
    }
    return D;
}


//
// SOLUCION
//

double resolver(const vector<vector<arista>>& D, const vector<vector<arista>>& T, const vector<arista>& X, int s, int t) {
    vector<double> Ds = bellford(D, s);
    vector<double> Tt = bellford(T, t);
    double min = Ds[t];
    for (const arista& x : X) {
        if (Ds[x.a] + x.w + Tt[x.b] < min) // s --> a -> b --> t
            min = Ds[x.a] + x.w + Tt[x.b];
        if (Ds[x.b] + x.w + Tt[x.a] < min) // s --> b -> a --> t
            min = Ds[x.b] + x.w + Tt[x.a];
    }
    return min == INF ? -1 : min;
}

int main(int argc, char** argv) {

    int c = 0, n = 0, m = 0, k = 0, s = 0, t = 0;
    cin >> c;
    for (int i = 0; i < c; ++i) {

        cin >> n >> m >> k >> s >> t;
        s--; t--;
        vector<vector<arista>> D(n, vector<arista>()); // digrafo de entrada
        vector<vector<arista>> T(n, vector<arista>()); // digrafo transpuesto
        vector<arista> X(k); // calles a considerar
        int a, b; double w;
        for (int j = 0; j < m; ++j) {
            cin >> a >> b >> w;
            a--; b--;
            D[a].push_back((arista) {a, b, w});
            T[b].push_back((arista) {b, a, w});
        }
        for (int j = 0; j < k; ++j) {
            cin >> a >> b >> w;
            a--; b--;
            X[j] = (arista) {a, b, w};
        }
        cout << (long) resolver(D, T, X, s, t) << endl;
    }

    return 0;
}

