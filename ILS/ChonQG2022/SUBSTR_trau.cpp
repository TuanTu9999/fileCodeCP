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

int n, a[30];
string s;

bool check(int mask) {
    vector<int> cur;
    for (int i = 0; i < n; i++) if (mask & (1 << i)) cur.push_back(a[i]);

    int l = 0, r = cur.size() - 1, val = cur[0];
    while (l < r) {
        if (cur[l] == cur[r] && cur[l] == val) {
            l++;
            r--;
            val ^= 1;
        } else {
            return 0;
        }
    }
    return 1;
}

signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "INOUT"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".ANS", "w", stdout);
    }

    cin >> n >> s;
    for (int i = 0; i < n; i++) a[i] = (s[i] == 'a' | s[i] == 'e' | s[i] == 'i' | s[i] == 'o' | s[i] == 'u');

    int Ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int bitOn = __builtin_popcount(mask);
        if (bitOn % 2 == 0) {
            if (check(mask)) maximize(Ans, bitOn);
        }
    }

    cout << n - Ans;

    return 0;
}