#include <bits/stdc++.h>

using namespace std;

#define MAX 1010

int points[MAX][MAX];
int trees[MAX][MAX];
struct Fenwick2D {

    int n, m;

    void build(int nn, int nm) {
        n = nn; m = nm;

        for(int i = 0; i <= n ; ++i){
            for (int j = 0; j <= m; ++j) {
                trees[i][j] = points[i][j] = 0;
            }
        }
    }

    void update(int x , int y, int value) {
        x ++; y ++;
        for(; x <= n ; x += factor(x)){
            for (int j = y; j <= m ; j += factor(j)) {
                trees[x][j] += value;
            }
        }
    }

    int sum(int x, int y) {
        x ++; y ++;
        int sum = 0;
        for(; x > 0 ; x -= factor(x)){
            for(int j = y ; j > 0; j -= factor(j)){
                sum += trees[x][j];
            }
        }

        return sum;
    }


    int factor(int x) {
        return x & (-x);
    }
};


int main () {

//    freopen("test.in", "r", stdin);

    int t , q, option, x , y , xLower, xUpper, yLower, yUpper;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    Fenwick2D tree = Fenwick2D();
    for(int i = 0; i < t; ++i){
        cin >> q;
        printf("Case %d:\n", i + 1);

        tree.build(1001, 1001);

        for(int j = 0; j < q; ++j){
            cin >> option;

            if( option == 0) {
                cin >> x >> y;
                if (!points[x][y]) {
                    points[x][y] = 1;
                    tree.update(x, y, 1);
                }
            } else {
                cin >> xLower >> yLower >> xUpper >> yUpper;

                int sum = tree.sum(xUpper, yUpper) -
                          tree.sum(xLower - 1, yUpper) -
                          tree.sum(xUpper, yLower - 1) +
                          tree.sum(xLower - 1, yLower - 1);
                printf("%d\n", sum);
            }
        }
    }
}