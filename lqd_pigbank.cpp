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

int n, m, q, diff[maxn], c[maxn], pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>m;
    while(m--){
        int l, r; cin>>l>>r;
        diff[l] += 1;
        diff[r + 1] -= 1;
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += diff[i];
        c[sum]++;
    }
    for(int i = maxn - 3; i > 0; i--) pre[i] = pre[i + 1] + c[i];
    cin>>q;
    while(q--){
        int x; cin>>x;
        cout<<pre[x]<<'\n';
    }
    return 0;
}
