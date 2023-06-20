#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
//El problema se puede pensar como uno de corte mínimo:
//Al conectar los que prefieren Prim a la fuente, y los de Kruskal al sumidero, minimizar la discomformidad
//es equivalente a buscar un corte mínimo: dos amigos en S y V\S generan uno de discomformidad porque de S
//sale una arista de capacidad uno. La discomformidad de cambiarse de bando se ve en la relación que
//tienen los vértices con la fuente y el sumidero: si un estudiante votaba a Prim, pero se pasa a Kruskal,
// hay una nueva arista de S a V\S (de la fuente a ese estudiante) por lo que aumenta en uno.
//Si votaba a Kruskal también ocurre, pues ahora la arista es de el estudiante al sumidero.
//Para hacer la solución tomamos un algoritmo de flujo máximo, ya que son equivalentes

vector<vector<int>> N; // Red de flujo. La usamos para iterar por todas las aristas en O(m) en vez de O(n^2)
vector<vector<int>> capacitado; //matriz de flujos. En una posición ij el valor  es
                                // - 1 si la arista ij no existe, 0 si no tiene flujo
                                // y 1 si lo tiene
vector<vector<int>> R;          // red residual

bool BFS_aumento(vector<int>&padre) {
    padre[0] = -2;
    queue<int> q;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : N[cur]) {
            if (padre[next] == -1 && !capacitado[cur][next]) {
                padre[next] = cur;
                if (next == padre.size() - 1) return true; //encontró a t, se termina el camino de aumento
                q.push(next);
            }
        }
    }

    return false;
}

int corte_minimo() {
    //Implementación de https://cp-algorithms.com/graph/edmonds_karp.html#implementation
    int discomformidad = 0;
    vector<int> caminoDeAumento;
    caminoDeAumento.resize(N.size(), -1);
    while (BFS_aumento(caminoDeAumento)) {
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
    // Implementación de https://www.codingninjas.com/codestudio/library/fast-i-o-in-c
    // Sin esta optimización de IO, el juez considera que el algoritmo es demasiado lento
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; int m;
    cin >> n >> m;
    while (n != 0 || m != 0) {
        N = {{}}; capacitado = {{}};
        N.resize(n + 2, {}); //Agregamos 2 lugares para la fuente y el sumidero
        vector<vector<int>> capacitador(n+2, vector<int>(n+2,-1));
        capacitado = capacitador; //sobreescibimos el vector para cada instancia de m y n
        int k;
        for(int i = 1; i <= n; i++) {//creamos el grafo a partir de las aristas
            cin >> k;                // todas comienzan con flujo 0
            if (k) {
                N[0].push_back(i); //Si cree que prim es mejor, lo conectamos a la fuente
                capacitado[0][i] = 0;
            }
            else {
                N[i].push_back(n+1); //Si cree que kruskal es mejor, va al sumidero
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
