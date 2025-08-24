#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, m, u[maxn], v[maxn], w[maxn], Ans;
vector<int> g[maxn];
bool vis[maxn];

void DFS(int s){
    vis[s] = 1;
    for(int pos : g[s]){
        if(!vis[pos]) DFS(pos);
    }
}

bool check(int year){
    for(int i = 1; i <= m; i++){
        if(w[i] > year){
            g[v[i]].push_back(u[i]);
            g[u[i]].push_back(v[i]);
        }
    }
    int cnt = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cnt++;
            DFS(i);
        }
    }
    return (cnt > 1);
}

void process(){
    int l = -1, r = 1000;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            Ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
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
    cin >> n >> m;
    for(int i = 1; i <= m; i++) cin >> u[i] >> v[i] >> w[i];
    process();
    cout << Ans;
    return 0;
}
