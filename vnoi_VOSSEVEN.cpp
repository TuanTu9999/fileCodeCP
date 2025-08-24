#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

string s;
long long dp[maxn], Ans[maxn];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> s;
    int n = s.size(); s = ' ' + s + ' ';

    for (int i = 1, d = 0; i <= n + 1; i++) {
        if (s[i] == '7') d++;
        else {
            Ans[1] += d;
            int m = d;
            for (int j = 2; j <= m; j++) {
                Ans[j] += --d;
            }
            d = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (Ans[i]) cout << i << ' ' << Ans[i] << '\n';
    }
    return 0;
}
