
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
    const int n = 1024;
    vector<vector<int>> arr;
public:
    BIT(){
        arr = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void add(int x, int y) {
        for(; x < n; x |= (x + 1)) {
            for(int yy = y; yy < n; yy |= (yy + 1)) {
                arr[x][yy]++;    
            }
        }
    }

    int query(int x, int y) {
        int acc = 0;
        for(; x >= 0; x = (x & (x + 1)) - 1){
            for(int yy = y; yy >= 0; yy = (yy & (yy + 1)) - 1) {
                acc += arr[x][yy];
            }
        }
        return acc;
    }

    int rQuery(int x1, int y1, int x2, int y2) {
        auto ret = query(x2, y2); 
        auto common = query(x1 - 1, y1 - 1);

        auto sect1 = query(x1 - 1, y2);
        auto sect2 = query(x2, y1 - 1);

        return ret - sect1 - sect2 + common;
    }
};

void solveD(){
  int t; scanf("%d", &t);
  
  for(auto tt = 1; tt <= t; ++tt) {
    printf("Case %d:\n", tt);
    BIT bit;
    set<pair<int, int>> seen;
    int q; scanf("%d", &q);

    while(q--) {
        int type; scanf("%d", &type);

        if(type == 0) {
            int x, y; scanf("%d%d", &x, &y);
            if(seen.count({x, y})) continue;
            seen.insert({x, y});
            bit.add(x, y);
        } else {
            int x1, y1, x2, y2; 
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            printf("%d\n", bit.rQuery(x1, y1, x2, y2));
        }
    }

  }
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
