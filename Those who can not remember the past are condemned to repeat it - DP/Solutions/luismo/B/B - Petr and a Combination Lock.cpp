/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Petr and a Combination Lock
	Online Judge: codeforces.com
	Idea: Bitmask at the face + some geometry + some modulus
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
const int lim = 1e5 + 2;

int n;

int arr[23];

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];


    // bitmask
    for(int mask = 0; mask < (1<<n); mask++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if((mask&(1<<i)) != 0)
                sum+= arr[i];
            else sum -=arr[i];
        }

        sum += n * 360;
        sum = sum % 360;

        if(sum == 0)
        {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
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

