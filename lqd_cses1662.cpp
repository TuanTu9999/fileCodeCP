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

int n, cnt[maxn];
llong ans, sum;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++){
        int x; cin>>x;
        if(x > 0) sum += x % n;
        else sum += n - ((-x) % n);
        ans += cnt[sum%n];
        cnt[sum%n]++;
    }
    cout<<ans;
    return 0;
}
