#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long Key;

unordered_map<Key,int> fenwick;

const int upper = 100002;

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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    update(2, 3, 12);
    update(224, 24, 13);
    update(1, 8, 1);

    cout << sum(1, 1) << endl;
    cout << sum(2, 3) << endl;
    cout << sum(1, 8) << endl;
    cout << sum(1000, 1000) << endl;
}