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

int f[maxn], n;

void sieve(int n){
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i) f[j]++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n;
    sieve(maxn - 3);
    while(n--){
        int x; cin>>x;
        cout<<f[x] + 1<<'\n';
    }
    return 0;
}
