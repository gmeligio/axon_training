#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 1001

typedef long long Key;

unordered_map<Key,int> fenwick;

const int upper = 1002;

int factor(int x) {
    return x & (-x);
}

Key merge(int x, int y) {
    return (((Key) x) << 32LL) ^ y;
}

unordered_map<Key, int>:: iterator it;
int sum (int x, int y) {
    int sum = 0;

    for(x ++ ; x > 0 ; x -= factor(x)) {
        for (int j = y + 1; j > 0; j -= factor(j)) {
            it = fenwick.find(merge(x, j));
            if( it != fenwick.end()){
                sum += it->second;
            }
        }
    }

    return sum;
}

int update(int x, int y, int value) {
    for(x ++; x <= upper; x += factor(x)){
        for (int j = y + 1; j <= upper; j += factor(j)) {
            fenwick[merge(x , j)] += value;
        }
    }
}

int t, p, q;
int points[MAX][MAX];

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    int option, x , y , xLower, xUpper, yLower, yUpper;
    for(int i = 0; i < t; ++i){
        cin >> q;
        printf("Case %d:\n", i + 1);

        for(int j = 0; j < q; ++j){
            cin >> option;

            if( option == 0) {
                cin >> x >> y;
                if (!points[x][y]) {
                    points[x][y] = 1;
                    update(x, y, 1);
                }
            } else {
                cin >> xLower >> yLower >> xUpper >> yUpper;

                int points = sum(xUpper, yUpper) -
                             sum(xLower - 1, yUpper) -
                             sum(xUpper, yLower - 1) +
                             sum(xLower - 1, yLower - 1);
                printf("%d\n", points);
            }
        }

        fenwick.clear();

        for(int k = 0; k < MAX ; ++k){
            for (int j = 0; j < MAX; ++j) {
                points[k][j] = 0;
            }
        }
    }
}