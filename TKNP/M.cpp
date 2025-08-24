#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, k;
pair<int, int> a[maxn];
long long Ans, pre[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i].second;
    for(int i = 1; i <= n; i++){
        int j = lower_bound(a + 1, a + i + 1, pair<int, int>(a[i].first - 2 * k, 0)) - a;
        Ans = max(Ans, pre[i] - pre[j - 1]);
    }
    cout << Ans;
    return 0;
}
