#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back

using namespace std;

const int maxn = 403;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, a[maxn][maxn];
llong pre[maxn][maxn], suf[maxn][maxn], ans = -1e18;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] = a[i][j];
            suf[i][j] = a[i][j];
            if (i > 1 && j > 1) pre[i][j] += pre[i - 1][j - 1];
            if (i > 1 && j < n) suf[i][j] += suf[i - 1][j + 1];
        }
    }

    for (int size = 1; size <= n; size++) {
        for (int i = size; i <= n; i++) {
            for (int j = size; j <= n; j++) {
                llong mainDiagSum = pre[i][j] - pre[i - size][j - size];
                llong antiDiagSum = suf[i][j - size + 1] - suf[i - size][j + 1];
                ans = max(ans, mainDiagSum - antiDiagSum);
            }
        }
    }

    cout << ans;
    return 0;
}
