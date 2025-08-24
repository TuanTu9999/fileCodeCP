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

int n, k, h[maxn], O;
llong ans;
map<int, int> c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>O>>n>>k;
    for(int i = 0; i < n; i++) cin>>h[i];
    int l = 0;
    for(int r = 0; r < n; r++){
        c[h[r]]++;
        while(c.size() > k && l < n){
            auto it = c.find(h[l]);
            (*it).second--;
            if((*it).second == 0) c.erase(it);
            l++;
        }
        ans += r - l + 1;
    }
    cout<<ans;
    return 0;
}
