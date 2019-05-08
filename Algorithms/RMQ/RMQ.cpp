//
// Created by Carlos on 5/8/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 100001
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

    vector<int> values;
    values.push_back(2);
    values.push_back(1);
    values.push_back(1);
    values.push_back(-1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    values.push_back(5);
    values.push_back(6);
    values.push_back(7);
    values.push_back(8);
    values.push_back(9);

    auto rmq = new RMQ<int>(values);

    cout << rmq->min(11, 11) << endl;

    return 0;
}