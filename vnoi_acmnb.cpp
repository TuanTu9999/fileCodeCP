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

const int maxn = 8e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, ans, a[maxn], b[maxn];
pii diff[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    for(int i = 0; i < 2*n; i++){
        cin>>a[i]>>b[i];
        diff[i] = {b[i] - a[i], i};
    }
    sort(diff, diff + 2*n);
    for(int i = 0; i < n; i++){
        ans += b[diff[i].second];
    }
    for(int i = n; i < 2*n; i++){
        ans += a[diff[i].second];
    }
    cout<<ans;
    return 0;
}
