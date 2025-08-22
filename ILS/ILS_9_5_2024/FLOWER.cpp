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

string s, t;

void process() {
    vector<int> pos1[26], pos2[26];
    cin >> s >> t;
    
    int n = s.size(); s = ' ' + s;
    int m = t.size(); t = ' ' + t;
    for (int i = 1; i <= n; i++) {
        pos1[s[i] - 'A'].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        pos2[t[i] - 'A'].push_back(i);
    }

    int Ans = 1e9;

    for (int i = 0; i < 26; i++) for (int x : pos1[i]) if (pos1[i].size() && pos2[i].size()) {
        int d1 = x - 1;
        int d3 = n - x;

        auto it = lower_bound(all(pos2[i]), x);
        if (it != pos2[i].end()) {
            int d2 = *it - 1;
            int d4 = m - *it;
            minimize(Ans, abs(d1 - d2) + abs(d2 - d3) + abs(d3 - d4) + abs(d4 - d1));
        }
        it = upper_bound(all(pos2[i]), x);
        if (it != pos2[i].begin()) {
            it--;
            int d2 = *it - 1;
            int d4 = m - *it;
            minimize(Ans, abs(d1 - d2) + abs(d2 - d3) + abs(d3 - d4) + abs(d4 - d1));
        }
    }

    cout << Ans << '\n';
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "FLOWER"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }

    int tt; cin >> tt;
    while (tt--) {
        process();
    }

    return 0;
} 