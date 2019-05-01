//
// Created by Kdver on 4/28/2019.
//

#include <bits/stdc++.h>

using namespace std;
#define MAX 100001

int values[MAX];

struct Fenwick {

    int n, tree[MAX];

    void build(int length, int *values) {
        n = length;
        memset(tree, 0, (n + 1) * sizeof(int));

        for(int i = 0; i < n; i ++){
            update(i, values[i]);
        }
    }

    void update(int index, int value) {
        index ++;
        while (index <= n) {
            tree[index] += value;
            index += factor(index);
        }
    }

    int sum(int index){
        index ++;
        int sum = 0;
        while (index > 0){
            sum += tree[index];
            index -= factor(index);
        }

        return sum;
    }

    int sum(int lower, int upper) {
        lower = max(0, lower);
        upper = min(n - 1 , upper);

        return sum(upper) - sum(lower - 1);
    }

    static int factor(int x) {
        return x & (-x);
    }
};

int main() {

//    freopen("test.in" , "r" , stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, q, option , index, amount, lower, upper;

    scanf("%d", &t);

    Fenwick tree = Fenwick();
    for(int i = 0; i < t; ++i){
        printf("Case %d:\n", i + 1);
        scanf("%d %d", &n, &q);

        for (int j = 0; j < n; ++j) {
            scanf("%d", &values[j]);
        }

        tree.build(n, values);

        for (int k = 0; k < q; ++k) {
            scanf("%d", &option);

            switch (option) {
                case 1:
                    scanf("%d", &index);
                    tree.update(index, -values[index]);
                    printf("%d\n", values[index]);
                    values[index] = 0;
                    break;
                case 2:
                    scanf("%d %d", &index, &amount);
                    tree.update(index, amount);
                    values[index] += amount;
                    break;
                case 3:
                    scanf("%d %d", &lower, &upper);
                    printf("%d\n", tree.sum(lower, upper));
                    break;
                default:break;
            }
        }
    }
}