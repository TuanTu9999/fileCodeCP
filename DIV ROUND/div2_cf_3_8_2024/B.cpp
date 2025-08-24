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

void sol(){
    cin>>n;
    veci a, b;
    for(int i = 0; i < n; ++i){
        int x; cin>>x;
        if(x & 1) b.push_back(x);
        else a.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(a.empty() || b.empty()){
        cout<<"0\n";
        return;
    }
    int ans = 0;
    for(int i = 0; i < (int)min(a.size(), b.size())); i++){
        if(a[i] < b
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    int t; cin>>t;
    while(t--) sol();
    return 0;
}
