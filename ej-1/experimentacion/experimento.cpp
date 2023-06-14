#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <tuple>

#include "./algoritmos/trafico.h"

using namespace std;

struct arista {
    int a;
    int b;
    double w; // peso
};

#if   SRC == 1
#define PATH "./out/runtime_djikstra_fast.csv"
#elif SRC == 2
#define PATH "./out/runtime_djikstra_slow.csv"
#elif SRC == 3
#define PATH "./out/runtime_bellford.csv"
#else
#define PATH "./out/runtime.csv"
#endif


//
// VARIABLES
//

#define REPEAT 10
#define START 1000
#define STOP 10000
#define STEP 1000


//
// MEDICION
//

vector<int> read_input(int size) {
    vector<int> input(size); string file_name = "./in/input_" + to_string(size);
    cout << file_name << endl;
    ifstream read_file(file_name);
    for (int i=0; i<size; i++) read_file >> input[i];
    read_file.close();
    return input;
}

double measure(const vector<vector<arista>>& D, const vector<vector<arista>>& T, const vector<arista>& X, int s, int t) {
    auto start = chrono::high_resolution_clock::now();
    resolver(D, T,  X,  s, t);

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = stop - start;
    return diff.count();
}


//
// MAIN
//

int main(int argc, char** argv) {
    int repeat = REPEAT;
    ofstream output_file; output_file.open(PATH);
    output_file << "n,time\n";

    for (int n = START; n <= STOP; n += STEP) {
        vector<int> input = read_input(n);
        int N = input[0]; int M = input[1]; int K = input[2]; int s = input[3]; int t = input[4];
        s--; t--;
        vector<vector<arista>> D(N, vector<arista>()); // digrafo de entrada
        vector<vector<arista>> T(N, vector<arista>()); // digrafo transpuesto
        vector<arista> X(K); // calles a considerar
        int a, b; double w;
        for (int j = 0; j < M; ++j) {
            cin >> a >> b >> w;
            a--; b--;
            D[a].push_back((arista) {a, b, w});
            T[b].push_back((arista) {b, a, w});
        }
        for (int j = 0; j < K; ++j) {
            cin >> a >> b >> w;
            a--; b--;
            X[j] = (arista) {a, b, w};
        }
        double counter = 0;
        for (int ignore=0; ignore<repeat; ignore++) {
            counter += measure(D, T, X, s, t);
        }
        double avg = counter / repeat;
        output_file << n << "," << avg << endl;
        cout << n << ": " << avg << endl;
    }

    output_file.close();
    return 0;
}
