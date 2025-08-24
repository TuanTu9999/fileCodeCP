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

int n, a[maxn], ans;

bool check(int k){
    set<int> c = {0};
    llong pre = 0;
    for(int i = 1; i <= n; i++){
        pre += a[i] - k;
        if(c.find(pre) != c.end()) return true;
        c.insert(pre);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    int l = *min_element(a + 1, a + n + 1), r = *max_element(a + 1, a + n + 1);
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid;
        }
        else r = mid - 1;
    }
    cout<<ans;
    return 0;
}
