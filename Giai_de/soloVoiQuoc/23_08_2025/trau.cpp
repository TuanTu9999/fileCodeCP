#include <bits/stdc++.h>

#define ll long long
#define el cout << '\n'
#define ii pair<ll, ll>
#define fi first
#define se second

using namespace std;

const int maxn = 1e5;
const int MOD = 1e9 + 7;
const int BASE = 256;

int n, mx_cnt = 0, mx_len;
string s;
ll h[maxn + 10], p[maxn + 10];
unordered_map<ll, int> mp;
ii mx = {0, 0};

ll get_hash(int l, int r)
{
    ll a = h[r] - h[l - 1] * p[r - l + 1] % MOD;
    a %= MOD;
    a += MOD;
    return a % MOD;
}
bool check(int x)
{
    mp.clear();
    int mx = 0;
    for (int i = 1; i <= n - x + 1; i++)
    {
        mp[get_hash(i, i + x - 1)]++;
        mx = max(mx, mp[get_hash(i, i + x - 1)]);
    }
    return mx >= mx_cnt;
}
int bs(int l, int r)
{
    int ans = l;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (check(m))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return ans;
}
bool cmp(int i, int j)
{
    int l = 1;
    int r = mx_len;
    int ans = 0;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (get_hash(i, i + m - 1) == get_hash(j, j + m - 1))
        {
            ans = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    if (ans == mx_len)
        return 0;
    return s[i + ans] < s[j + ans];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".ANS", "w", stdout);

    cin >> s;
    n = s.size();
    s = ' ' + s;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * BASE % MOD;
        h[i] = (h[i - 1] * BASE + s[i]) % MOD;
    }
    for (int i = 2; i <= n; i++)
    {
        ll hsh = get_hash(i - 1, i);
        mp[hsh]++;
        mx_cnt = max(mx_cnt, mp[hsh]);
    }
    cout << mx_cnt, el;
    if (mx_cnt == 0)
        return 0;
    mx_len = bs(1, n);
    mp.clear();
    for (int i = 1; i <= n - mx_len + 1; i++)
    {
//        cout << mx.fi << ' ' << mx.se, el;
//        for (int j = mx.se; j <= mx.se + mx_len - 1; j++)
//            cout << s[j];
//        el;
        mp[get_hash(i, i + mx_len - 1)]++;
        int x = mp[get_hash(i, i + mx_len - 1)];
        if (mx.fi < x)
            mx = {x, i};
        else if (mx.fi == x && cmp(i, mx.se))
            mx.se = i;
//        cout << mx.fi << ' ' << mx.se, el;
//        for (int j = mx.se; j <= mx.se + mx_len - 1; j++)
//            cout << s[j];
//        el;
//        el;
    }
//    mx_len = 2;
//    string t = "";
//    t += s[43];
//    t += s[44];
//    cout << t, el;
//    t = "";
//    t += s[22];
//    t += s[23];
//    cout << t, el;
//    cout << cmp(204, 449), el;
    for (int i = mx.se; i <= mx_len + mx.se - 1; i++)
        cout << s[i];
}
