//
// Created by Kdver on 4/28/2019.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX 200100

int values[MAX];
struct Fenwick {

    int n;
    int tree[MAX];

    void build(int length, int *values){
        memset(tree, 0, sizeof(tree));

        for( int i = 0; i < length; i++ ){
            update(i + 1, values[i]);
        }
    }

    void update(int index, int value){
        while (index <= n) {
            tree[index] += value;
            index += factor(index);
        }
    }

    int sum(int upper) {
        int sum = 0;

        while (upper > 0) {
            sum += tree[upper];
            upper -= factor(upper);
        }

        return sum;
    }

    int sum(int lower, int upper){
        lower = max(0, lower);
        upper = min(n - 1, upper);

        return sum(upper + 1) - sum(lower);
    }

    static int factor(int x) {
        return x & (-x);
    }

    void clean() {
        memset(tree, 0 , sizeof tree);
    }

};

int main() {

//    freopen("test.in", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, lower, upper, cases = 0;
    char task[4];

    memset(task, '\0', sizeof task);

    Fenwick tree = Fenwick();
    for(;;){
        cin >> n;

        if( n == 0 ) {
            break;
        }

        cases ++;

        for(int i = 0; i < n ; i ++){
            cin >> values[i];
        }
        tree.clean();
        tree.n = n;
        tree.build(n, values);

        if( cases != 1 ){
            cout << endl;
        }
        cout << "Case " << cases << ":\n";

        for(;;){
            cin >> task;
            if( task[0] == 'E' ){
                break;
            }

            switch (task[0]) {
                case 'M':
                    cin >> lower >> upper;
                    lower --; upper --;
                    cout << tree.sum(lower, upper) << endl;
                    break;
                case 'S':
                    cin >> lower >> r;
                    lower --;
                    tree.update(lower + 1, r - values[lower]);
                    values[lower] = r;
                    break;
                default:break;
            }
        }
    }

    return 0;
}