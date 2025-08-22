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

const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n, subtask;
double V, b[maxn], h[maxn], w[maxn], d[maxn];

bool calc(double preAns) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] > preAns) continue;
        sum += min((preAns - b[i]), h[i]) * d[i] * w[i];
    }
    return (V - sum) >= 1e-3;
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "FILL"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> b[i] >> h[i] >> w[i] >> d[i];
    cin >> subtask;

    double l = b[1], r = b[1] + 4e4, Ans = b[1];
    while (r - l >= 1e-4) {
        double mid = (l + r) / 2.0;
        if (calc(mid)) {
            Ans = mid;
            l = mid + 0.001;
        } else {
            r = mid - 0.001;
        }
    }

    cout << fixed << setprecision(2) << Ans;

    return 0;
}