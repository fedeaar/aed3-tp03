#ifndef TRAFICO
#define TRAFICO


#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <tuple>
#include <limits>

using namespace std;


struct arista {
    int a;
    int b;
    double w;
};

double resolver(const vector<vector<arista>>& D, const vector<vector<arista>>& T, const vector<arista>& X, int s, int t);


#endif // TRAFICO
