#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define COMP(x) x.resize(unique(all(x)) - x.begin())
template<typename T>
inline bool maximize(T &res, const T &val) {
    if (res < val) return res = val, 1;
    return 0;
}
template<typename T>
inline bool minimize(T &res, const T &val) {
    if (res > val) return res = val, 1;
    return 0;
}

using namespace std;

#define maxn ((int)(1e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const __int128_t MOD = (__int128_t)13043817825332782193;
// #define ONLINE_JUDGE

string s;
int n, AnsPos, AnsLen, AnsCnt;
__int128_t hs[maxn], pw[maxn];

inline __int128_t getHash(int l, int r) {
    return ((hs[r] - hs[l - 1] * pw[r - l + 1]) % MOD + MOD) % MOD;
}

bool Min(int st1, const int st2, int len) {
    int l = 1, r = len, res = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (getHash(st1, st1 + mid - 1) == getHash(st2, st2 + mid - 1)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (res == len) return 0;
    return s[st1 + res] < s[st2 + res];
}

bool check(int len) {
    unordered_map<__int128_t, int> cnt;
    for (int i = 1; i + len - 1 <= n; i++) {
        __int128_t cur = getHash(i, i + len - 1);
        cnt[cur]++;
        if (cnt[cur] == AnsCnt) {
            return 1;
        }
    }
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> s;
    n = (int)s.size();
    s = ' ' + s;

    pw[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw[i] = (pw[i - 1] << 8) % MOD;
        hs[i] = ((hs[i - 1] << 8) + s[i]) % MOD;
    }

    unordered_map<__int128_t, int> cnt;
    for (int i = 2; i <= n; i++) {
        cnt[getHash(i - 1, i)]++;
        maximize(AnsCnt, cnt[getHash(i - 1, i)]);
    }

    int l = 2, r = n;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            AnsLen = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cnt.clear();
    for (int i = 1; i + AnsLen - 1 <= n; i++) {
        __int128_t cur = getHash(i, i + AnsLen - 1);
        cnt[cur]++;
        if (cnt[cur] == AnsCnt && (AnsPos == 0 || Min(i, AnsPos, AnsLen))) {
            AnsPos = i;
        }
    }

    cout << AnsCnt << '\n';
    for (int i = AnsPos; i <= AnsPos + AnsLen - 1; i++) {
        cout << s[i];
    }

    return 0;
}
