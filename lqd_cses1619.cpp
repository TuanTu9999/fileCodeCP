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

int n;
vector<pii> a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        a.push_back({l, 1});
        a.push_back({r, -1});
    }
    sort(a.begin(), a.end());
    int d, dmax;
    d = dmax = 0;
    for(int i = 0; i < (int)a.size(); i++){
        d += a[i].second;
        dmax = max(dmax, d);
    }
    cout<<dmax;
    return 0;
}
