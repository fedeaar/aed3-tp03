#include <vector>
#include <limits>

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


//
// DIJKSTRA
//

class dijkstra_queue {
public:
    struct entrada {int clave; double valor; };

    dijkstra_queue(vector<double> D, int s): I(D.size()), Q(D.size()) {
        for (int i = 0; i < D.size(); ++i) {
            Q[i] = entrada{i, D[i]};
            I[i] = i;
        }
        heapify();
    };

    entrada pop() {
        // asume |Q| > 0
        entrada tope = Q[0];
        Q[0] = Q[Q.size()-1];
        I[Q[0].clave] = 0;
        I[tope.clave] = -1;
        Q.pop_back();
        down_heap(0);
        return tope;
    }

    bool empty() {
        return Q.empty();
    }

    void decrease_key(int i, long valor) {
        if (i >= I.size() || I[i] == -1 || I[i] >= Q.size())
            return;
        Q[I[i]].valor = valor;
        up_heap(I[i]);
    }

private:
    vector<entrada> Q;
    vector<int> I;

    void down_heap(int i) {
        int izq = 2*i + 1;
        int der = 2*i + 2;
        int min = i;
        int n = Q.size();
        if (izq < n && Q[izq].valor < Q[min].valor)
            min = izq;
        if (der < n && Q[der].valor < Q[min].valor)
            min = der;
        if (min != i) {
            // swap
            entrada tmp = Q[min];
            Q[min] = Q[i]; I[Q[min].clave] = min;
            Q[i] = tmp; I[Q[i].clave] = i;
            down_heap(min);
        }
    }

    void up_heap(int i) {
        int pred = (i - 1) / 2;
        int n = Q.size();
        if (pred < n && pred >= 0 && Q[pred].valor > Q[i].valor) {
            // swap
            entrada tmp = Q[pred];
            Q[pred] = Q[i]; I[Q[pred].clave] = pred;
            Q[i] = tmp; I[Q[i].clave] = i;
            up_heap(pred);
        }
    }

    void heapify() {
        int n = Q.size();
        for (int i = n/2; i >= 0; --i)
            down_heap(i);
    }
};

vector<double> dijkstra(const vector<vector<arista>>& G, int s) {
    int n = G.size();
    vector<double> D(n, INF); D[s] = 0; // distancias
    dijkstra_queue Q(D, s);
    while (!Q.empty()) {
        dijkstra_queue::entrada u = Q.pop();
        for (const arista& v : G[u.clave])
            if (D[v.b] > D[u.clave] + v.w) {
                D[v.b] = D[u.clave] + v.w;
                Q.decrease_key(v.b, D[v.b]);
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
