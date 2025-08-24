#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;

int n, m;
vector<int> g[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int k, l; cin >> k >> l;
        g[k].push_back(l);
        g[l].push_back(k);
    }
    for(int i = 1; i <= n; i++){
        cout << g[i].size() << ' ';
        sort(g[i].begin(), g[i].end());
        for(int x : g[i]) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
