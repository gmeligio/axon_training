//
// Created by Carlos on 5/8/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 20
#define LOG_MAX 17

template <class T>
class RMQ {
public:

    explicit RMQ(vector<T> values) {
        this->n = values.size();
        build(values);
    }

    T max(int lower, int upper) {
        int exponent = static_cast<int>(log2((upper - lower + 1)));
        return std::max(sparse[1][upper - (1 << exponent) + 1][exponent], sparse[1][lower][exponent]);
    }

    T min(int lower, int upper) {
        int exponent = static_cast<int>(log2((upper - lower + 1)));
        return std::min(sparse[0][upper - (1 << exponent) + 1][exponent], sparse[0][lower][exponent]);
    }
private:

    int n;
    T sparse[2][MAX][LOG_MAX];

    void build(vector<T> values) {

        for(int i = 0; i < n; ++ i){
            sparse[0][i][0] = sparse[1][i][0] = values[i];
        }

        for(int j = 1; (1 << j) <= n ; ++ j) {
            for(int i = 0; i + (1 << (j - 1)) - 1 < n; ++ i){
                sparse[0][i][j] = std::min(sparse[0][i][j - 1], sparse[0][i + (1 << (j - 1))][j - 1]);
                sparse[1][i][j] = std::max(sparse[1][i][j - 1], sparse[1][i + (1 << (j - 1))][j - 1]);
            }
        }
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

//    freopen("test.in", "r", stdin);

    int n;
    cin >> n;

    vector<int> values(static_cast<unsigned int>(n));
    for(int i = 0; i < n; ++ i){
        cin >> values[i];
    }

    auto rmq = new RMQ<int>(values);

    int lower = 0, upper = 0, sol = -1;

    while(upper < n) {

        while(rmq->max(lower, upper) - rmq->min(lower, upper) <= 1) {
            sol = std::max(sol, upper - lower + 1);
            upper ++;
            if( upper >= n ) {
                break;
            }
        }

        while(rmq->max(lower, upper) - rmq->min(lower, upper) > 1) {
            lower ++;
        }
    }

    cout << sol << endl;

    return 0;
}