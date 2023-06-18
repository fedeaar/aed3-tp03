#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <tuple>

#include "./algoritmos/trafico.h"

using namespace std;


#if   SRC == 1
#define PATH "./out/runtime_djikstra_fast_ralo.csv"
#elif SRC == 2
#define PATH "./out/runtime_djikstra_slow_ralo.csv"
#elif SRC == 3
#define PATH "./out/runtime_djikstra_queue_ralo.csv"
#else
#define PATH "./out/runtime.csv"
#endif


//
// VARIABLES
//

#define REPEAT 100
#define START 10000
#define STOP 100000
#define STEP 10000

vector<int> read_input(int size) {
    vector<int> input(size*6 + 5); string file_name = "./inputs/input_" + to_string(size);
    cout << file_name << endl;
    ifstream read_file(file_name);
    for (int i=0; i<size*6 + 5; i++) read_file >> input[i];
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
        int N = n; int m = 2*n; int K = 0; int s = 1; int t = 2;
        s--; t--;
        vector<vector<arista>> D(N+1, vector<arista>()); // digrafo de entrada
        vector<vector<arista>> T(N+1, vector<arista>()); // digrafo transpuesto
        vector<arista> X; // calles a considerar
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
