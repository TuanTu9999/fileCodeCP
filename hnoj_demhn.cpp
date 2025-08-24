#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 10;
const int MOD = 1e9 + 7;

string s;
int k, cnt[maxn];
long long Ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "DEMHN"
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> s >> k;
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1];
        cnt[i] += (s[i] == 'H');
    }

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'N') {
            Ans += ((1LL * k * cnt[i]) % MOD) + ((1LL * k * (k - 1) / 2 * cnt[n]) % MOD);
            Ans %= MOD;
        }
    }

    cout << Ans;
    return 0;
}
