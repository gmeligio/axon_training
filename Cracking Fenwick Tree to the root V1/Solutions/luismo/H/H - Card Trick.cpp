/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: H - Card Trick 
	Online Judge:
	Idea: Fenwick Tree + Binary Search, implementation
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


class FenwickTree
{
    private:
        vector<ll> tree;
        inline int lowBit(int i) {return i&-i;}
    public:

        FenwickTree(){}

        FenwickTree(int len)
        {
            tree.resize(len, 0);
        }

        FenwickTree(int len, int v)
        {
            tree.resize(len, v);
        }

        void update(int idx, ll upd)
        {
            for(int i = idx; i < tree.size(); i+= lowBit(i))
                tree[i]+= upd;
        }

        ll retrieve(int idx)
        {
            ll sum = 0;
            for(int i = idx; i > 0; i-= lowBit(i))
                sum += tree[i];
            return sum;
        }

        ll retrieve(int a, int b)
        {
            if(a > b)
                return 0;
            return retrieve(b) - retrieve(a - 1);
        }
};
FenwickTree * ft;

int tc, n;


// finds the kth active element
int findKth(int L, int R, int k)
{
    while(L < R)
    {
        int mid = (L+R)/2;
        int cnt = ft->retrieve(L, mid);
        if(cnt >= k)
            R = mid;
        else
        {
            L = mid + 1;
            k-= cnt;
        }
    }
    return L;
}



void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> n;

        ft = new FenwickTree(n+2);
        for(int i = 1; i <= n+1; i++)
            ft->update(i, 1);

        int init = 1;

        vector<int> answ (n+1, -1);

        for(int i = 1; i <= n; i++)
        {
            int cnt = ft->retrieve(init, n);

            if(cnt >= i + 1)
            {
                int a = findKth(init, n, i + 1);
                answ[i] = a;

                ft->update(a, -1);

                init = findKth(a + 1, n + 1, 1);
                if(init > n)
                    init = 1;
            }
            else
            {
                init = 1;
                int x = (i + 1 - cnt);
                cnt = ft->retrieve(1, n);
                if(cnt < x)
                    x = ((x-1) % cnt) + 1;

                int a = findKth(1, n, x);
                answ[i] = a;

                ft->update(a, -1);

                init = findKth(a + 1, n + 1, 1);
                if(init > n)
                    init = 1;
            }
        }

        vector<int> pri (n + 1, 0);
        for(int i = 1; i < answ.size(); i++)
            pri[answ[i]] = i;

        for(int i = 1; i < pri.size(); i++)
            cout << pri[i] << " ";

        cout << endl;
    }
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

	solve();
}
