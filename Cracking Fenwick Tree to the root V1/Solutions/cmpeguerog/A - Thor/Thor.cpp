#include <bits/stdc++.h>

using namespace std;

#define MAX 300010

const int upper = 300001;

int n, q, notification, type, app, lower, first;

vector<int> apps[MAX];

int fenwick[MAX];

int factor(int x){
    return x & (-x);
}

int update(int index , int value){
    for(; index <= upper; index += factor(index)){
        fenwick[index] += value;
    }
}

int sum(int index) {
    int acum = 0;
    for(; index > 0; index -= factor(index)){
        acum += fenwick[index];
    }

    return acum;
}

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    lower = 0;
    for(int i = 0; i < q; ++ i){
        cin >> type;

        if( type == 1 ) {
            cin >> app;
            notification ++;
            update(notification, 1);
            apps[app].push_back(notification);
        } else if( type == 2 ) {
            cin >> app;

            while (!apps[app].empty()){
                int value = apps[app].back();
                update(value, -1);
                apps[app].pop_back();
            }
        } else {
            cin >> first;
            lower = max(lower, first);
        }

        cout << sum(upper) - sum(lower) << endl;
    }
}