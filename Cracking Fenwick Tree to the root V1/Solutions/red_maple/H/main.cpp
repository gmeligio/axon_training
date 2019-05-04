
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

class BIT{
private:
    int n;
    vector<int> arr;
public:
    BIT(int n) {
        this->n = n;
        arr = vector<int>(n);
        for(auto i = 0; i < n; ++i) {
            update(i, 1);
        }
    }

    void update(int i, int delta) {
        for(; i < n; i |= (i + 1)) {
            arr[i] += delta;
        }
    }

    int query(int i) {
        int acc = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) {
            acc += arr[i];
        }
        return acc;
    }

    void print() {
        for(auto it : arr) {
            cout << it << " ";
        }
        cout <<endl;
    }
};

void print(vector<int> & v) {
    for(auto a : v) {
        cout << a << " ";
    }
    cout <<endl;
}

int bSearch(int l, int r, int k, BIT & bit) {
    while(l < r) {
        int mid = (l + r) / 2;
        int midQ = bit.query(mid);
        if( k <= midQ) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

void solveH(){
    int t; cin >> t;
    while(t--) {
        int n;  cin >> n;
        BIT bit(n);
        vector<int> ret(n);

        int slots = n;
        int ind = -1;
        for(int mov = 1; mov <= n; ++mov) {
            int curSum = bit.query(ind);
            int findFree = (curSum + mov + 1) % slots;
            if(findFree == 0) findFree = slots;
            slots--;

            int next = bSearch(0, n - 1, findFree, bit);
            ret[next] = mov;
            bit.update(next, -1);
            ind = next;
        }

        print(ret);

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(precision);
    cout.setf(ios_base::fixed);
    solveH();
    return 0;
}