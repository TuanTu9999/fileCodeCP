#include <bits/stdc++.h>

using namespace std;

int n, c, a[20], Ans;

void solusion_1() {
    for (int mask = 0; mask < (1 << n); mask++) {
        int temp = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((mask >> i) & 1) temp += a[i + 1];
        }
        if (temp <= c) Ans = max(Ans, temp);
    }
}

void solusion_2() {
    bool dp[5001];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int s = c; s >= a[i]; s--) {
            dp[s] |= dp[s - a[i]];
        }
    }

    for (int i = 1; i <= c; i++) {
        if (dp[i]) Ans = i;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> c >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    solusion_2();

    cout << Ans;

    return 0;
}
