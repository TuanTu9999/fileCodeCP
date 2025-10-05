#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()

using namespace std;

const int maxn = 1e5 + 10;

int n;
long long L, R;
int a[maxn];
long long pw10[100];

void process() {
    cin >> n >> L >> R;
    vector<int> val[9];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        val[(int)log10(a[i]) + 1].push_back(a[i]);
    }

    for (int len = 1; len <= 8; len++) {
        sort(ALL(val[len]));
    }

    long long Ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int len = 1; len <= 8; len++) {
            long long Low = L - pw10[len] * a[i];
            long long High = R - pw10[len] * a[i];
            if (High < 0) break;

            int l = lower_bound(ALL(val[len]), Low) - val[len].begin();
            int r = upper_bound(ALL(val[len]), High) - val[len].begin();
            Ans += r - l;
        }
    }

    cout << Ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    pw10[0] = 1;
    for (int i = 1; i <= 8; i++) {
        pw10[i] = pw10[i - 1] * 10ll;
    }

    int tt;
    cin >> tt;
    while (tt--) {
        process();
    }

    return 0;    
}
