#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int m, n, a[maxn], Lim;
bool dp[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> a[i];
    dp[1] = 1;
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= m; i++) {
            if(j >= a[i] && !dp[j - a[i]]) dp[j] = 1;
        }
    }

    if(dp[n]) cout << "Marisa";
    else cout << "Reimu";
    return 0;
}
