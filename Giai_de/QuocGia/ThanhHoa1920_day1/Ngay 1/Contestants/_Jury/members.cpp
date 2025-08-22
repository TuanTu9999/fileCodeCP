#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;

ll n, k, a[maxn];
vector < int > res;
bool dx[maxn];
struct node
{
    ll sum, pos, Max;
    node()
    {
        sum = pos = Max = 0;
    }
} t[4 * maxn];

void update(int type, int id, int L, int R, int i, int v)
{
    if(i < L || i > R)
        return;
    if(L == R)
    {
        if(type == 0)
        {
            t[id].Max = v;
            t[id].sum = 1;
            t[id].pos = i;
        }
        else
        {
            t[id].Max = -1;
            t[id].sum = t[id].pos = 0;
        }
        return;
    }

    int mid = (L + R) / 2;
    update(type, id * 2, L, mid, i, v);
    update(type, id * 2 + 1, mid + 1, R, i, v);

    t[id].Max = max(t[id * 2].Max, t[id * 2 + 1].Max);
    t[id].sum = t[id * 2].sum + t[id * 2 + 1].sum;
    if(t[id * 2].Max == t[id * 2 + 1].Max)
        t[id].pos = min(t[id * 2].pos, t[id * 2 + 1].pos);
    else if(t[id * 2].Max < t[id * 2 + 1].Max)
        t[id].pos = t[id * 2 + 1].pos;
    else
        t[id].pos = t[id * 2].pos;
}

node Get(int id, int L, int R, int u, int v)
{
    node Tree;
    if(v < L || u > R)
    {
        Tree.Max = -1;
        Tree.sum = Tree.pos = 0;
        return Tree;
    }
    if(u <= L && R <= v) return t[id];

    int mid = (L + R) / 2;
    node Left = Get(id * 2, L, mid, u, v);
    node Right = Get(id * 2 + 1, mid + 1, R, u, v);

    Tree.Max = max(Left.Max, Right.Max);
    Tree.sum = Left.sum + Right.sum;
    if(Left.Max == Right.Max)
        Tree.pos = min(Left.pos, Right.pos);
    else if(Left.Max < Right.Max)
        Tree.pos = Right.pos;
    else
        Tree.pos = Left.pos;
    return Tree;
}

int Find(int id, int L, int R, int v)
{
    if(L == R) return L;

    int mid = (L + R) / 2;
    if(t[id * 2].sum >= v)
        return Find(id * 2, L, mid, v);
    return Find(id * 2 + 1, mid + 1, R, v - t[id * 2].sum);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    if(fopen("members.inp", "r"))
    {
        freopen("members.inp", "r", stdin);
        freopen("members.out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        update(0, 1, 1, n, i, a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        int x = Find(1, 1, n, min(n, k + 1));
        node tree = Get(1, 1, n, 1, x);
        int Max = tree.Max;
        int pos = tree.pos;
        k -= (Get(1, 1, n, 1, pos).sum - 1);
        update(1, 1, 1, n, pos, a[i]);
        res.push_back(a[pos]);
        dx[pos] = true;
        if(k <= 0) break;
    }
    for(int i : res) cout << i << ' ';
    for(int i = 1; i <= n; i++) if(!dx[i]) cout << a[i] << ' ';
}
