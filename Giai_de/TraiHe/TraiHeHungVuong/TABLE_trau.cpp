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

#define maxn (int)(410)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, m, a[maxn][maxn], Ans;
int cnt[(int)1e6 + 10];

bool check(int w) {
    int res = 0;

    for (int j = 1; j + w - 1 <= n; j++) {
        int top = 1;
        int del = 0;
        vector<int> e;

        for (int i = 1; i <= m; i++) {
            for (int k = j; k <= j + w - 1; k++) {
                if (cnt[a[i][k]] == 1) {
                    del++;
                }
                cnt[a[i][k]]++;
                e.push_back(a[i][k]);
            }

            while (del) {
                for (int k = j; k <= j + w - 1; k++) {
                    if (cnt[a[top][k]] == 2) {
                        del--;
                    }
                    cnt[a[top][k]]--;
                }
                top++;
            }
            maximize(res, i - top + 1);
        }

        for (int x : e) cnt[x] = 0;
    }

    if (res == 0) return 0;
    maximize(Ans, res * w);
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".ANS", "w", stdout);
#endif

    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
    	for (int j = 1; j <= n; j++) {
    		cin >> a[i][j];
    	}
    }

    for (int i = n; i > 0; i--) {
        check(i);
    }

    cout << Ans;

    return 0;
}