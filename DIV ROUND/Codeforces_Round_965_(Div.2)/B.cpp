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

int t, n, a[maxn], b[maxn];

void sol(){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        b[i] = a[i];
    }
    reverse(a, a + n);
    if(n & 1){
        for(int i = 0; i < n; i++){
            if(a[n/2+1] != b[i] && a[i] != b[n/2+1]) swap(a[i], a[n/2+1]);
        }
    }
    for(int i = 0; i < n; i++) cout<<a[i]<<' ';
    el;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>t;
    while(t--) sol();
    return 0;
}
