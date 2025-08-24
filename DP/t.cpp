#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 3;
int n, m, w[maxn], v[maxn], dp[maxn], trace[maxn], ansW, ans;
vector<int> pos;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME "BAG"
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= n; i++){
        for(int j = m; j >= w[i]; j--){
            if(dp[j] < dp[j - w[i]] + v[i]){
                dp[j] = dp[j - w[i]] + v[i];
                trace[j] = i;
            }
            ans = max(ans, dp[j]);
        }
    }
    cout << dp[m] << '\n';
    for(int s = m; s > 0 && trace[s]; s -= w[trace[s]]) pos.push_back(trace[s]);
    sort(pos.begin(), pos.end());
    for(int i : pos){
        cout << i << ' ';
        ansW += w[i];
    }
    cout << '\n' << ansW;
    return 0;
}
