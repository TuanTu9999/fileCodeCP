#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n;
long long dp[maxn];
pair<int, int> p[maxn];
map<int, long long> mp;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p + 1, p + n + 1, cmp);

    dp[1] = p[1].second - p[1].first + 1;
    mp[p[1].second] = dp[1];
    for(int i = 2; i <= n; i++) {
        auto it = mp.lower_bound(p[i].first);
        long long len = p[i].second - p[i].first + 1;
        if(it != mp.begin()) {
            it--;
            len += (*it).second;
        }
        dp[i] = max(dp[i - 1], len);
        mp[p[i].second] = max(mp[p[i].second], dp[i]);
    }
    cout << dp[n];
    return 0;
}
