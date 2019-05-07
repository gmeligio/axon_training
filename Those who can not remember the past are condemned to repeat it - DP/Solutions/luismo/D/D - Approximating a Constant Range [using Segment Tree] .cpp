/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Approximating a Constant Range
	Online Judge: codeforces.com
	Idea: Segment Tree storigin Max/Min. At each step do binary search to see the greater sub-segmet with differences not greater than one
	O(NlogN^2)
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

int n;
int arr[lim];

int mx[lim << 2];
int mn[lim << 2];

void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        mx[idx] = mn[idx] = upd;
        return;
    }
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    mx[idx] = max(mx[le], mx[ri]);
    mn[idx] = min(mn[le], mn[ri]);
}

pii retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return mkp(mx[idx], mn[idx]);

    if(L > QR || R < QL)
        return mkp(-1, mod + 59);

    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

    pii s1 = retrieve(le, L, mid, QL, QR);
    pii s2 = retrieve(ri, mid + 1, R, QL, QR);
    // merge
    pii ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
    return ret;
}


void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int answ = 0;
    // backwards linear scan
    for(int i = n - 1; i >= 0; i--)
    {
        // current element
        int k = arr[i];

        update(0, 0, n, i, k);

        // upperbound
        int le = i, ri = n;
	// binary search
        while(le < ri)
        {
            int mid = (le + ri) / 2;
	    // query the Segment Tree
            pii rr = retrieve(0, 0, n, i, mid);

            if(abs(rr.first - rr.second) > 1)
            {
                ri = mid;
            }
            else le = mid + 1;
        }

        // update the aswer
        if(le - i > answ)
            answ = le - i;
    }

    // print the answer
    cout << answ;
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
	else if(fopen("/media/luismo/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
