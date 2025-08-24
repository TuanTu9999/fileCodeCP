#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

int n, k;
long long Ans, pre[maxn][maxn];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x; cin >> x;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + x;
        }
    }

    for (int i = k; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            Ans = max(Ans, pre[i][j] - pre[i - k][j] - pre[i][j - k] + pre[i - k][j - k]);
        }
    }

    cout << Ans;

    return 0;
}
