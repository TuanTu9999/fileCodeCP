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

llong s = 1, a[maxn];

int sizeDigit(llong x){
    int res = 0;
    while(x){
        res++;
        x /= 10;
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    int n; cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    if(a[0] == 0) return cout<<0, 0;
    for(int i = 0; i < n; i++){
        if(sizeDigit(s) + sizeDigit(a[i]) > 18 || s * a[i] > ool) return cout<<"-1", 0;
        s *= a[i];
    }
    if(sizeDigit(s) > 18 || s > ool) return cout<<"-1", 0;
    cout<<s;
    return 0;
}
