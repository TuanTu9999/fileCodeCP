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

#define maxn ((int)(2e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, q, diff[maxn], comp[maxn];
pii qu[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> q;
    comp[++comp[0]] = 1;
    comp[++comp[0]] = n + 1;
    for (int i = 1; i <= q; i++) {
    	int l, r; 
    	cin >> l >> r;
    	qu[i] = pii(l, r);
    	comp[++comp[0]] = l;
    	comp[++comp[0]] = r + 1;
    }

    sort(comp + 1, comp + comp[0] + 1);
    comp[0] = unique(comp + 1, comp + comp[0] + 1) - comp - 1;

    for (int i = 1; i <= q; i++) {
    	int l = qu[i].first;
    	int r = qu[i].second;

    	int idxL = lower_bound(comp + 1, comp + comp[0] + 1, l) - comp;
    	int idxR = lower_bound(comp + 1, comp + comp[0] + 1, r + 1) - comp;

    	if (l <= r) {
    		diff[idxL]++;
	    	diff[idxR]--;
    	} else {
    		diff[idxL]++;
    		diff[1]++;
    		diff[idxR]--;
    	}
    }

    for (int i = 1; i <= comp[0]; i++) {
    	diff[i] += diff[i - 1];
    }

    int Max = -1e9, Cnt = 0;
    for (int i = 1; i < comp[0]; i++) {
        if (maximize(Max, diff[i])) {
            Cnt = comp[i + 1] - comp[i];
        } else if (diff[i] == Max) {
            Cnt += comp[i + 1] - comp[i];
        }
    }

    cout << Max << ' ' << Cnt;

    return 0;
}