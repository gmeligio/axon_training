#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAX 1000010

ll tree[MAX], c, k;
int n, m , u, v, p;
char operation[2];

int factor(int x){
    return x & (-x);
}

void update(int index ,ll value){
    index ++;
    for(; index <= n; index += factor(index)){
        tree[index] += value;
    }
}

ll sum(int index) {

    ll sum = 0;
    index ++;

    for(; index > 0; index -= factor(index)){
        sum += tree[index];
    }
    return sum;
}

void build() {
    memset(tree, 0, sizeof tree);
}

int main() {
//    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> c;
    build();

    for(int i = 0; i < m; ++i){
        cin >> operation;
        if( operation[0] == 'Q' ) {
            cin >> p;
            cout << sum(p - 1) + c << endl;
        } else if( operation[0] == 'S' ) {
            cin >> u >> v >> k;
            update(u - 1, k);
            update(v, -k);
        }
    }
}