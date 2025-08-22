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

int n, a, b;

namespace sub1 {
    bool check() {
        return n <= 2e6;
    }

    void process() {
        int Ans = 0;
        for (int x = 1; x < n; x++) {
            maximize(Ans, min(a / x, b / (n - x)));
        }

        cout << Ans;
    }
}

namespace sub2 {
    void process() {
        int x = 1, Ans = 1;
        while (x <= n) {
            int c = a / x;
            int r = a / c;
            maximize(Ans, min(a / r, b / (n - r)));
            x = r + 1;
        }

        cout << Ans;
    }
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "CAKE"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n >> a >> b;

    if (sub1::check()) sub1::process();
    else sub2::process();

    return 0;
}