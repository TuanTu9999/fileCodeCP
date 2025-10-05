#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;

int n;
pair<int, int> a[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n;
    long long SumF = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].second;
        SumF += a[i].second;
    }
    for (int i = 1; i <= n; i++) cin >> a[i].first;

    if (SumF < n) {
        cout << -1;
        return 0;
    }

    sort(a + 1, a + n + 1);
        
    long long Ans = 0;
    int need = n;
    for (int i = 1; i <= n; i++) {
        if (need == 0) break;
        int take = min(a[i].second, need);
        need -= take;
        Ans += 1ll * take * a[i].first;
    }

    cout << Ans;

    return 0;    
}
