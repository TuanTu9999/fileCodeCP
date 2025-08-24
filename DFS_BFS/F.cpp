#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, k;
vector<int> g[maxn], ans;
bool vis[maxn];

void DFS(int u){
    vis[u] = 1;
    ans.push_back(u);
    for(int pos : g[u]){
        if(!vis[pos]){
            DFS(pos);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int len; cin >> len;
        for(int j = 1; j <= len; j++){
            int x; cin >> x;
            g[i].push_back(x);
        }
    }
    DFS(k);
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(int x : ans) cout << x << ' ';
    return 0;
}
