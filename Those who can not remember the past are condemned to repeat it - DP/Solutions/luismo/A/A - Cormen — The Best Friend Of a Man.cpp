/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Cormen — The Best Friend Of a Man
	Online Judge: codeforces.com
	Idea: Ad-Hoc
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 2;

int n, k;
int arr[lim];

void solve()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    if(n == 1)
    {
        cout << 0 << endl;
        cout << arr[0];
        return;
    }

    int sum = 0;

    for(int i = 0; i <  n - 1; i++)
    {
        if(arr[i] + arr[i + 1] < k)
        {
            int aux = k - (arr[i] + arr[i+1]);
            arr[i+1] += aux;
            sum += aux;
        }
    }

    cout << sum << endl;
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}

