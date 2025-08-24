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

int t;

void sol(){
    vector<pii> a;
    int n, m, s; cin>>n>>s>>m;
    for(int i = 0; i < n; i++){
        int l, r; cin>>l>>r;
        a.push_back({l, r});
    }
    sort(a.begin(), a.end());
    if(a[0].first >= s){
        cout<<"YES\n";
        return;
    }
    for(int i = 1; i < n; i++){
        if(a[i].first - a[i - 1].second >= s){
            cout<<"YES\n";
            return;
        }
    }
    if(m - a[n - 1].second >= s){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>t;
    while(t--) sol();
    return 0;
}
