
#include <bits/stdc++.h>
#include <limits.h>
#include <algorithm>  
#include <numeric>

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

const int precision = 16;
const int modulo =  1000000007; // 10^9 + 7
const ll lmodulo =  1000000007; // 10^9 + 7

const double EPS = 1e-9;

class BIT {
private:
    int n = 0;
    vector<ll> arr;

    ll inner_sum(int ind) {
        ll acc = 0;
        for(; ind >= 0; ind = (ind & (ind + 1)) - 1) {
            acc += arr[ind];
        }
        return acc;
    }

public:
    BIT(int size) {
        n = size;
        arr.assign(n, 0ll);
    }

    void add(int ind, ll delta) {
        for(; ind < n; ind |= (ind + 1)) {
            arr[ind] += delta;
        }
    }

    void set(int ind, int v) {
        ll prev = sum(ind, ind);
        ll delta = v - prev;
        add(ind, delta);
       
    }

    ll sum(int l, int r) {
        return inner_sum(r) - inner_sum(l - 1);
    }

    void print() {
        cout << "Printing : " <<endl;
        for(auto it : arr) {
            cout << it << " ";
        }
        cout <<endl;
    }
};

void solveB(){
    int tcase = 1;
    int n;
    cin >> n;
    string query = "q";

    while(n != 0) {
        cout << "Case " << tcase << ":" <<endl;
        tcase++;

        BIT bit(n);
        for(int i = 0; i < n; ++i){
            int v; cin >> v;
            bit.add(i, v);
        }

        cin >> query;
        while(query != "END") {
            int a, b; cin >> a >> b;
            if(query == "M") {
                cout << bit.sum(a - 1, b - 1) <<endl;;
            } else {
                bit.set(a - 1, b);
            }
            cin >> query;
        }

        cin >> n;
        if(n != 0) cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveB();
    return 0;
}