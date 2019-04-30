//
// Created by Kdver on 4/28/2019.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX 1030

int values[MAX][MAX];
int tree[MAX][MAX];
char option[3];

int n;

int factor(int x) {
    return x & (-x);
}

void update(int xIndex, int yIndex, int value) {
    xIndex ++; yIndex ++;
    for (; xIndex <= n; xIndex += factor(xIndex)) {
        for (int j = yIndex; j <= n ; j += factor(j)) {
            tree[xIndex][j] += value;
        }
    }
}

int sum(int xIndex, int yIndex) {
    int sum = 0;
    xIndex ++; yIndex ++;
    for(; xIndex > 0; xIndex -= factor(xIndex)) {
        for (int j = yIndex; j > 0 ; j -= factor(j)) {
            sum += tree[xIndex][j];
        }
    }

    return sum;
}

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0, x, y, num, xLower, yLower, xUpper, yUpper;

    cin >> t;

    for (int i = 0; i < t; ++i) {
        if( i != 0 ) {
            cout << "\n";
        }
        cin >> n;
        for(;;) {
            cin >> option;
            if(option[0] == 'E'){
                break;
            } else if( option[0] == 'S' && option[1] == 'E' ) {
                cin >> x >> y >> num;
                update(x, y, num - values[x][y]);
                values[x][y] = num;
            } else if( option[0] == 'S' && option[1] == 'U' ) {
                cin >> xLower >> yLower >> xUpper >> yUpper;
                cout << sum(xUpper, yUpper) - sum(xLower - 1, yUpper) - sum(xUpper , yLower - 1) + sum(xLower - 1, yLower - 1) << endl;
            }
        }

        for(int i = 0; i < MAX ; i++){
            for(int j = 0; j < MAX; j ++){
                tree[i][j] = values[i][j] = 0;
            }
        }
    }

    return  0;
}