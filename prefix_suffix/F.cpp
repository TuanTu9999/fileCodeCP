#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, p;
long long ans, pre;
map<long long, int> mp;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> p;
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre += x;
        auto it = mp.find(pre - p);
        if(it != mp.end()) ans += (*it).second;
        mp[pre]++;
    }
    cout << ans;
    return 0;
}
