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

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

llong n, sum[maxn], pre[maxn], ans = -ool;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        sum[i] = sum[i - 1] + x;
        pre[i] = min(pre[i - 1], sum[i]);
    }
    for(int i = 1; i <= n; i++) ans = max(ans, sum[i] - pre[i - 1]);
    cout<<ans;
    return 0;
}
