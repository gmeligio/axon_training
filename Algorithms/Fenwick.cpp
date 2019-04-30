//
// Created by Kdver on 4/25/2019.
//

#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int fenwick[MAX], n;

int factor(int x){
    return x & (-x);
}

void update(int index, int value){
    index ++;
    for(; index <= n; index += factor(index)){
        fenwick[index] += value;
    }
}

void build(int *values) {
    for(int i = 0; i < n ; i ++){
        update(i, values[i]);
    }
}

int sum(int index) {
    index ++;
    int result = 0;
    for(; index > 0; index -= factor(index)) {
        result += fenwick[index];
    }
    return result;
}

int sum (int lower, int upper) {
    return sum(upper) - sum(lower - 1);
}

int main() {

    int freq[] = {2, 1, 1, -1, 2, 3, 4, 5, 6, 7, 8, 9};
    n = sizeof(freq)/sizeof(freq[0]);

    build(freq);

    cout << sum(4, 5) << endl;
    cout << sum(3, 4) << endl;
    return 0;
}