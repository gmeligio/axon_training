/*
    Date 05/13/2019
    Brenda E Ramirez.
*/

#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define endl '\n'
using ll = long long;

const int precision = 16;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;

class DSU {
private:
    int n;
    vector<vector<int>> parent;
    vector<vector<int>> size;
public:
    DSU(int n) {
        this->n = n;
        parent = vector<vector<int>>(2, vector<int>(n, 0));
        size = vector<vector<int>>(2, vector<int>(n, 0));

        for(auto i = 0; i < n; ++i) {
            parent[0][i] = i;
            parent[1][i] = i;

            size[0][i] = 1;
            size[1][i] = 1;
        }
    }

    int getParent(int u, int c) {
        if(parent[c][u] == u) return u;
        return parent[c][u] = getParent(parent[c][u], c);
    }

    int getSize(int u, int c) {
        return size[c][u];
    }

    void mergeSets(int u, int v, int c) {
        u = getParent(u, c);
        v = getParent(v, c);

        if(size[c][u] > size[c][v]) {
            swap(u, v);
        }

        parent[c][u] = parent[c][v];
        size[c][v] += size[c][u];
    }
};

void solveD(){
    int n; cin >> n;
    
    DSU dsu(n);

    for(int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        dsu.mergeSets(u, v, c);
    }

    ll acc = 0;
    for(auto i = 0; i < n; ++i) {
        if(dsu.getParent(i, 0) == i) { // only 0
            ll size = dsu.getSize(i, 0);
            size *= size - 1;
            acc += size;
        }

        if(dsu.getParent(i, 1) == i) { // only 1
            ll size = dsu.getSize(i, 1);
            size *= size - 1;
            acc += size;
        }

        ll mixSize = dsu.getSize(dsu.getParent(i, 0), 0) - 1;
        mixSize *= dsu.getSize(dsu.getParent(i, 1), 1) - 1;

        acc += mixSize;
    }

    cout << acc;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveD();
    return 0;
}