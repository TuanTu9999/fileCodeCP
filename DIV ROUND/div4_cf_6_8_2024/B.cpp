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

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int t;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>t;
    while (t--) {
        int a, b, c, d, ans = 0;
        cin>>a>>b>>c>>d;
        if((a > c && b > d) || (a >= c && b > d) || (a > c && b >= d)) ans++;
        if((a > d && b > c) || (a >= d && b > c) || (a > d && b >= c)) ans++;
        if((b > c && a > d) || (b >= c && a > d) || (b > c && a >= d)) ans++;
        if((b > d && a > c) || (b >= d && a > c) || (b > d && a >= c)) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}
