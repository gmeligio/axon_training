//
// Created by Carlos on 5/3/2019.
// Email: cmpeguerog@gmail.com
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define MAX 1000010
struct Query {
    int position, lower, upper;

    Query():
        position(0),lower(0), upper(0){}
    Query(int nPosition, int nLower, int nUpper):
        position(nPosition),lower(nLower), upper(nUpper){}

    bool operator <(const Query& query) const {
        return upper < query.upper;
    }
} queries[MAX];

class Fenwick {
public:
    explicit Fenwick(int n) {
        this->n = n;
        for(int i = 0; i <= n; ++ i){
            tree[i] = 0;
        }
    }

    void update(int index, int value) {
        for(index ++; index <= n ; index += factor(index)){
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

    const static int limit = 30010;
    int tree[limit];

    int factor(int x) {
        return x & (-x);
    }
};

int previous[MAX];
int values[MAX];
int sol[MAX];

int main() {

    int n , q;

    scanf("%d", &n);

    for(int i = 0; i < n; ++ i){
        scanf("%d",&values[i]);
        previous[values[i]] = -1;
    }
    scanf("%d",&q);

    for(int i = 0, lower, upper; i < q; ++ i){
        scanf("%d %d", &lower, &upper);

        queries[i] = Query(i, lower - 1, upper - 1);
    }

    sort(queries, queries + q);

    auto fenwick = new Fenwick(n);

    int qIndex = 0;
    for(int i = 0; i < n ; ++ i){
        if( previous[values[i]] != -1 ) {
            fenwick->update(previous[values[i]], -1);
        }
        fenwick->update(i, 1);
        previous[values[i]] = i;

        for(; qIndex < q && queries[qIndex].upper == i; qIndex ++) {
            sol[queries[qIndex].position] = fenwick->sum(queries[qIndex].lower, queries[qIndex].upper);
        }
    }

    for(int i = 0; i < q; ++ i){
        printf("%d\n", sol[i]);
    }
}