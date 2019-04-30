
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

class BIT {
private:
    int n;
    vector<ll> arr;
public:
    BIT(int size, int c) {
        this->n = size;
        arr = vector<ll>(n);
        rAdd(0, size - 1, c);
    }

    void add(int ind, int c) {
        for(;ind < n; ind |= (ind + 1)) {
            arr[ind]+= c;
        }
    }

    ll query(int p) {
        ll acc = 0;
        for(;p >= 0; p = (p & (p + 1)) - 1) {
            acc += arr[p];
        }
        return acc;
    }

    void rAdd(int l, int r, int c) {
        add(l, c);
        add(r + 1, -c);
    }

    void print() {
        cout << "-----"<<endl;
        for(auto it : arr) {
            cout << it << " ";
        }
        cout<<endl << "-----"<<endl;
    }
};
void solveE(){
    int n, m, c; cin >> n >> m >> c;

    BIT bit(n + 1,  c);

   // bit.print();

    while(m--){
        char q; cin >> q;
        if(q == 'Q') {
            int p; cin >> p; p--;
            cout << bit.query(p) <<endl;
        } else {
            int u, v, k;
            cin >> u >> v >>k;
            u--; v--;
            bit.rAdd(u, v, k);
    
            // bit.print();
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveE();
    return 0;
}
