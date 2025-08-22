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

const int maxn = 2e5 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

int n, a[maxn];
long long sum;

namespace sub1 {
    bool check() {
        return n <= 5000;
    }

    int cost[5010][5010];
    void process() {
        for (int i = 1; i <= n; i++) {
            long long curSum = a[i];
            cost[i][i] = 1;
            for (int j = i + 1; j <= n; j++) {
                cost[i][j] = cost[i][j - 1];
                if (curSum + a[j] <= sum) curSum += a[j];
                else {
                    cost[i][j]++;
                    curSum = a[j];
                }
            }
        }

        long long Ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                Ans += cost[i][j];
            }
        }

        cout << Ans;
    }
}

namespace sub2 {
    long long dp[maxn], pre[maxn];

    void process() {
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
            int j = lower_bound(pre, pre + i + 1, pre[i] - sum) - pre;
            minimize(dp[i], dp[j] + i);
        }

        long long Ans = 0;
        for (int i = 1; i <= n; i++) Ans += dp[i];
        cout << Ans;
    }
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "DHH"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    cin >> n >> sum;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sub2::process();

    return 0;
}