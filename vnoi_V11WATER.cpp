#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, a[maxn], L[maxn], R[maxn];
long long Ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) L[i] = max(L[i - 1], a[i]);
    for (int i = n; i > 0; i--) R[i] = max(R[i + 1], a[i]);

    for (int i = 1; i <= n; i++) {
        Ans += max(min(L[i], R[i]) - a[i], 0);
    }

    cout << Ans;

    return 0;
}
