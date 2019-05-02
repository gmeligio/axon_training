
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


int getNextPow(int n) {
    int p = 1;

    while(n >= p) {
        p <<= 1;
    }
    return p;
}

class BIT {
private:
    int n;
    vector<ll> arr;
public:
    BIT(int size){
        n = getNextPow(size);
        arr = vector<ll>(n, 0l);
    }

    void add(int ind, int delta) {
        for(; ind < n; ind |= (ind + 1)) {
            arr[ind]+= delta;
        }
    }

    ll query() {
        int ind = n - 1;
        return query(ind);
    }

    ll query(int ind) {
        ll acc = 0;
        for(; ind >= 0; ind = (ind & (ind + 1)) - 1) {
            acc += arr[ind];
        }
        return acc;
    }

    ll rQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    void clear(int ind) {
        auto cur = rQuery(ind, ind);
        if(cur == 0) return;
        add(ind, -cur);
    }

    void print() {
        cout << "****" << endl;
        for(auto it : arr) {
            cout << it << " ";
        }
        cout << endl << "****" << endl;
    }
};

void solveA(){
    int n, q;
    cin >> n >> q;
    int e = 1;
    list<pair<int, int>> pastQ;
    unordered_map<int, list<list<pair<int,int>>::iterator>> seen;

    BIT bit(n);
    while(q--){
        int op, val;
        cin >> op >> val;
        val--;
        if(op == 1) {
            auto it = pastQ.emplace(pastQ.end(), val, e);
            seen[val].emplace_back(it);
            e++;
            bit.add(val, 1);
        }else if(op == 2){
            bit.clear(val);
            for(auto it : seen[val]) {
                pastQ.erase(it);
            }
            seen.erase(val);
        } else {
            val++;
            while(!pastQ.empty() and pastQ.front().second <= val){
                auto ind = pastQ.front();pastQ.pop_front();
                bit.add(ind.first, -1);
                seen[ind.first].pop_front();
            }
        }
        cout  <<   bit.query() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveA();
    return 0;
}
