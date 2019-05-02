/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: DQUERY
	Online Judge: SPOJ
	Idea: Sweep Line. Offline Queries. Binary Indexed Tree
*/
#include <iostream>
#include <cstdio>
// Containers
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
// Algorithm
#include <algorithm>
#include <cstring>
#include <cmath>
// Constants
#define MAXN 1000001
#define MOD 1000000007
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define nint(i) sf("%d",&i);
#define nlong(i) sf("%lld",&i);


using namespace std;

const int lim = 1e6;

int n, Q;
int marks[lim];
int arr[lim];

struct FenwickTree
{
	int tree[30000 + 7];

	inline int low_bit(int i){return i & -i;}

	FenwickTree() {
		for (int i = 0; i <= n; i++) {
			tree[i] = 0;
		}
	}

	void update(int idx, int v)
	{
		for(int i = idx; i <= n; i+= low_bit(i))
		tree[i]+= v;
	}

	int retrieve(int idx)
	{
		int rett = 0;
		for(int i = idx; i > 0; i-= low_bit(i))
		rett+= tree[i];
		return rett;
	}

};

struct query
{
	int id, l, r;
} qq[lim];

bool cmp_query(query f, query s)
{
	return f.r < s.r;
}

int answ[lim];

void solve()
{
	cin >> n;
	// reading integers
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> Q;
	// reading queries
	for(int i = 0; i < Q; i++)
		cin >> qq[i].l >> qq[i].r, qq[i].id = i;

	// sort queries
	sort(qq, qq + Q, cmp_query); //

	//for(int i = 0 ;i < Q; i++)
	//cout << qq[i].l << " " << qq[i].r << "\n";

	FenwickTree ft;

	int q_idx = 0;
	// sweep line
	for(int i = 1; i <= n; i++)
	{
		// if set before
		if(marks[ arr[i] ] > 0)
		{
			ft.update(marks[ arr[i] ], -1);
			ft.update(i, 1);
		}
		else
		ft.update(i, 1);

		// update
		marks[ arr[i] ] = i;

		// if in a current query
		while(q_idx < Q && qq[q_idx].r == i)
		{
			int aux = ft.retrieve(qq[q_idx].r ) - ft.retrieve(qq[q_idx].l - 1);

			answ[ qq[q_idx].id ] = aux;

			q_idx++;
		}
	}

	for(int i = 0; i < Q; i++)
		cout << answ[i] << "\n";
}

void open_file()
{
	// freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
	//open_file();

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}