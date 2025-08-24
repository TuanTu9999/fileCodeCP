#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10;
const int INF = 1e6;

int n, F[INF + 10], c[INF + 10];
long long Ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    for(int i = 1; i * i <= INF; i++) {
        for(int j = 1; j <= INF / (i * i); j++) {
            F[i * i * j] = j;
        }
    }
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        c[F[x]]++;
    }
    for(int i = 1; i <= INF; i++)
        Ans += 1LL * c[i] * (c[i] - 1) / 2;
    cout << Ans;
    return 0;
}
