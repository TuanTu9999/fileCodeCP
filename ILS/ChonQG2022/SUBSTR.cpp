#include <bits/stdc++.h>
#define debug(a) cerr << (a) << ' '
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define MASK(x) ((1LL) << (x))
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define eb emplace_back
#define pb push_back

// #pragma GCC             optimize("Ofast")
// #pragma GCC             optimize("O3")
// #pragma GCC             optimize("unroll-loops")
// #pragma GCC             target("avx,avx2,fma")

using namespace std;

template<typename T>
bool maximize(T &res, const T &val) {
    if (res < val) {
        res = val;
        return 1;
    }
    return 0;
}

template<typename T>
bool minimize(T &res, const T &val) {
    if (res > val) {
        res = val;
        return 1;
    }
    return 0;
}

const int maxn = 1e4 + 10;
const int MOD = 1e9 + 696969;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define base 5

int pre[maxn][2], nex[maxn][2];
int n, a[maxn], Ans;
string s;

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "SUBSTR"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n >> s;
    for (int i = 0; i < n; i++) a[i + 1] = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u';

    a[0] = -1;

    for (int i = 0; i <= 1; i++) {
        nex[n + 1][i] = n + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][a[i]] = i;
    }
    for (int i = n; i > 0; i--) {
        for (int j = 0; j <= 1; j++) {
            nex[i][j] = nex[i + 1][j];
        }
        nex[i][a[i]] = i;
    }

    for (int j = 0; j <= 1; j++) {
        int l = 0, r = n + 1, tar = j, cur = 0;
        while (nex[l + 1][tar] < pre[r - 1][tar]) {
            cur += 2;
            l = nex[l + 1][tar];
            r = pre[r - 1][tar];
            tar ^= 1;
        }
        maximize(Ans, cur);
    }

    cout << n - Ans;

    return 0;
}