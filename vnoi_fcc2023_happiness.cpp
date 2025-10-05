#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, m;
pair<int, int> a[maxn];
long long Ans;
bool check[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    int MaxSecond = 0, pos = 0;
    for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;

    sort(a + 1, a + m + 1, greater<pair<int, int>>());

    for (int i = 1; i <= m; i++) {
        if (MaxSecond < a[i].second || (pos != 0 && a[pos].first < a[i].first)) {
            MaxSecond = a[i].second;
            pos = i;
        }
    }

    for (int i = 1; i <= m; i++) {
        if (a[i].first < MaxSecond || n == 0) break;
        Ans += a[i].first;
        check[i] = 1;
        n--;
    }

    if (check[pos]) {
        Ans += 1ll * n * a[pos].second;
    } else {
        Ans += a[pos].first + 1ll * (n - 1) * a[pos].second;
    }
    cout << Ans;
    
    return 0;
}
