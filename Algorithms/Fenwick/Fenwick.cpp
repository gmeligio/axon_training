#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

class Fenwick {
public:

    explicit Fenwick(int n, const vector<int> &values) {
        this->n = n;
        tree = vector<int>(static_cast<unsigned int>(n + 1), 0);

        build(values);
    }

    void update(int index, int value) {
        for(index ++; index <= n; index += factor(index)){
            tree[index] += value;
        }
    }

    int sum(int index) {
        int result = 0;

        for(index ++; index > 0; index -= factor(index)){
            result += tree[index];
        }

        return result;
    }

    int sum(int lower, int upper) {
        return sum(upper) - sum(lower - 1);
    }

private:
    int n;
    vector<int> tree;

    int factor(int x) {
        return x & (-x);
    }

    void build(const vector<int> &values){
        for(int i = 0; i < values.size(); ++ i) {
            update(i, values[i]);
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

    auto fenwick = new Fenwick(values.size(), values);
    cout << fenwick->sum(4, 5) << endl;
    cout << fenwick->sum(3, 4) << endl;
    return 0;
}