/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1267 - Points in Rectangle (II)
	Online Judge: LightOJ
	Idea: Sweep Line + Fenwick Tree
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

int tc;
int p, q;


struct pt
{
    int x, y;
    pt(){}
    pt(int xx, int yy){x = xx; y = yy;}
};

struct event
{
    pt fir, sec;
    int type;
    int qNmb;
    int id;

    event(){}
    event(pt f, pt s, int t)
    {fir = f; sec = s; type = t;}
};
vector<event> events;

bool cmp(event a, event b)
{
    if(a.fir.x == b.fir.x)
        return a.type < b.type;

    return a.fir.x < b.fir.x;
}

// >> COORDINATES COMPRESSION
set<int> rbTree;
map<int, int> comp;
// << COORDINATES COMPRESSION

// >> FENWICK TREE

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
// << FENWICK TREE

// to print answer
int answ[lim];

void solve()
{
    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        rbTree.clear();
        comp.clear();
        events.clear();

        pf("Case %d:\n", cs);

        // reading
        sf("%d%d", &p, &q);
        // reading points
        for(int i = 0; i < p; i++)
        {
            int x, y;
            sf("%d%d", &x, &y);
            rbTree.insert(x);
            rbTree.insert(y);
            // add the event
            event e = event(pt(x, y), pt(-1, -1), 1);

            events.push_back(e);
        }

        // reading rectangles
        for(int i = 0; i < q; i++)
        {
            int x1,y1,x2,y2;
            sf("%d%d%d%d", &x1, &y1, &x2, &y2);
            rbTree.insert(x1);
            rbTree.insert(y1);
            rbTree.insert(x2);
            rbTree.insert(y2);

            // create the event
            // opening
            event e1 = event(pt(x1, y1), pt(x1, y2), 0);
            // closing
            event e2 = event(pt(x2, y1), pt(x2, y2), 2);
            e1.id = e2.id = i;

            events.push_back(e1);
            events.push_back(e2);
        }

        // compressing
        int cnt = 1;
        for(set<int>::iterator it = rbTree.begin(); it != rbTree.end(); it++)
            comp[(*it)] = cnt++;
        // end compression

        // sort fucking events
        sort(events.begin(), events.end(), cmp);

        // build the Fenwick Tree
        FenwickTree * ft = new FenwickTree(cnt + 3);

        // sweeping the fucking line
        for(int i = 0; i < events.size(); i++)
        {
            event e = events[i];

            if(e.type == 1)
            {
                pt p = e.fir;
                int x = comp[p.x];
                int y = comp[p.y];

                ft->update(y, 1);
            }
            else if(e.type == 0)
            {
                int a = comp[e.fir.y];
                int b = comp[e.sec.y];

                int k = ft->retrieve(a, b);

                answ[e.id] = -k;
            }
            else
            {
                int a = comp[e.fir.y];
                int b = comp[e.sec.y];

                int k = ft->retrieve(a, b);

                answ[e.id] += k;
            }
        }
        // print the answer
        for(int i = 0; i < q; i++)
            pf("%d\n", answ[i]);
    }
}


int main()
{
    
    solve();
}
