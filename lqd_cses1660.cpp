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

int n, k, a[maxn];
llong sum, ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];
    int l = 0;
    for(int r = 0; r < n; r++){
        sum += a[r];
        while(sum > k && l < n){
            sum -= a[l];
            l++;
        }
        if(sum == k) ans++;
    }
    cout<<ans;
    return 0;
}
