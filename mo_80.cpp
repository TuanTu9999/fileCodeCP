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

const int maxn = 1e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, l, r, a[maxn];
llong ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>l>>r;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    for(int j = 1; j < n; j++){
        int high = upper_bound(a, a + j, r - a[j]) - a - 1;
        int low = lower_bound(a, a + j, l - a[j]) - a;
        if(low <= high) ans += high - low + 1;
    }
    cout<<ans;
    return 0;
}
