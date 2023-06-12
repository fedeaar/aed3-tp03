#include <vector>
#include <iostream>
#include <queue>
using namespace std;
vector<vector<int>> N; // Red de flujo. La usamos para iterar por todas las aristas en O(m)
vector<vector<int>> capacitado; //matriz de capacidades. En una posición ij el valor  es
                                // - 1 si la arista ij no existe, 0 si no tiene flujo
                                // y 1 si lo tiene
vector<vector<int>> R;          // red residual
vector<bool> marcados;          // vector de booleanos para el dfs

bool BFS_aumento(vector<int>&CDA) {
    CDA[0] = -2;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : N[cur]) {
            if (CDA[next] == -1 && !capacitado[cur][next]) {
                CDA[next] = cur;
                if (next == CDA.size() - 1) return true;
                q.push(next);
            }
        }
    }

    return false;
}

void DFS_aumento(vector<int>&CDA, int v) {
    marcados[v] = true;
    if (v == N.size()+1) return;
    for (int w : R[v]) {
        if (marcados[w]) continue;
        else {
            CDA[w] = v; //marcamos los anteriores para reconstruir el camino aumentado
            DFS_aumento(CDA,w);
        }
    }
}

void armar_camino(vector<int>&CDA) {
    vector<int> temp;
    int i = CDA.size()-1;
    while(i != -1) {
        temp.push_back(i);
        i = CDA[i];
    }
    CDA = temp;
}

int corte_minimo() {
    int discomformidad = 0;
    vector<int> caminoDeAumento;
    caminoDeAumento.resize(N.size(), -1);
    while (BFS_aumento(caminoDeAumento)) {
        //R = {{}};
        //R.resize(N.size(), {});
        /*for (int i = 0; i < N.size(); i++) {    //Armamos la red de aumento de acuerdo a su definicion
            for (int j = 0; j < N[i].size(); j++) {
                if (!capacitado[i][N[i][j]]) R[i].push_back(N[i][j]);
                if (capacitado[i][N[i][j]]) R[N[i][j]].push_back(i);
            }
        }
        DFS_aumento(caminoDeAumento, 0);
        if (!marcados[marcados.size()-1]) { // si está marcado, devolvemos el flujo contando cada unidad
            int res = 0;                    // de flujo hacia el sumidero
            for (int i = 0; i < capacitado.size(); i++) {
                res += (capacitado[i][capacitado.size()-1] == 1);
            }
            return res;
        }

        armar_camino(caminoDeAumento);
        for (int i = 0; i < caminoDeAumento.size() - 1; i++) {
            int origen = caminoDeAumento[i + 1]; //Actualizamos los valores de flujo de acuerdo al camino
            int dest = caminoDeAumento[i];      // de aumento
            if (capacitado[origen][dest] == 0) capacitado[origen][dest] = 1;
            if (capacitado[dest][origen] != -1) capacitado[dest][origen] = 0;
        } */
    discomformidad++;
    int cur = caminoDeAumento.size()-1;
    while (cur != 0) {
        int prev = caminoDeAumento[cur];
        capacitado[prev][cur] = 1;
        capacitado[cur][prev] = 0;
        cur = prev;
        }
    caminoDeAumento = {};
    caminoDeAumento.resize(N.size(), -1);
    }
    return discomformidad;
}

int main() {
    int n; int m;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        N = {{}}; capacitado = {{}};
        N.resize(n + 2, {}); //Agregamos 2 lugares para la fuente y el sumidero
        vector<vector<int>> capacitador(n+2, vector<int>(n+2,-1));
        capacitado = capacitador;
        int k;
        for(int i = 1; i <= n; i++) {//creamos el grafo a partir de las aristas
            cin >> k;                // todas comienzan con flujo 0
            if (k) {
                N[0].push_back(i);
                capacitado[0][i] = 0;
            }
            else {
                N[i].push_back(n+1);
                capacitado[i][n+1] = 0;
            }
        }
        int i; int j;
        for(int v = 0; v < m; v++) {
            cin >> i >> j;
            N[i].push_back(j);
            N[j].push_back(i);
            capacitado[i][j] = 0;
            capacitado[j][i] = 0;
        }
        cout << corte_minimo() << "\n";
        cin >> n >> m;
    }
    return 0;
}