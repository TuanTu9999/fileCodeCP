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

int n, a[102], f[maxn], target;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>target;
    for(int i = 0; i < n; i++) cin>>a[i];
    f[0] = 1;
    for(int s = 1; s <= target; s++){
        for(int i = 0; i < n; i++){
            if(s >= a[i]) (f[s] += f[s - a[i]])%=MOD;
        }
    }
    cout<<f[target];
    return 0;
}
