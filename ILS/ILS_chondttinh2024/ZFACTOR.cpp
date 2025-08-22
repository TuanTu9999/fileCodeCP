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

const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n, k;

int F[maxn], cnt[maxn];
void sieve(int lim) {
    for (int i = 1; i <= lim; i++) F[i] = i;
    for (int i = 2; i <= lim; i++) if (i == F[i]) {
        for (int j = 2 * i; j <= lim; j += i) {
            minimize(F[j], i);
        }
    }
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "ZFACTOR"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n >> k;

    sieve(k);
    for (int i = 1; i <= k; i++) cnt[F[i]]++;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }

    return 0;
}