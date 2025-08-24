#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

int n, m;
long long dist[maxn], mi[maxn], ma[maxn], dp[maxn];
vector<pair<int, int>> g[maxn];

void dijkstra(int u){
    for(int i = 1; i <= n; i++) dist[i] = INF;
    dist[u] = 0;
    dp[u] = 1;
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> q;
    q.push(pair<long long, int>(0LL, u));
    while(q.size()){
        u = q.top().second;
        long long tmpCost = q.top().first;
        q.pop();
        if(tmpCost > dist[u]) continue;
        for(pair<int, int> pos : g[u]){
            int v = pos.first;
            long long cost = pos.second;
            if(dist[v] > dist[u] + cost){
                dist[v] = dist[u] + cost;
                mi[v] = mi[u] + 1;
                ma[v] = ma[u] + 1;
                dp[v] = dp[u];
                q.push(pair<long long, int>(dist[v], v));
            }
            else if(dist[v] == dist[u] + cost){
                mi[v] = min(mi[v], mi[u] + 1);
                ma[v] = max(ma[v], ma[u] + 1);
                (dp[v] += dp[u]) %= MOD;
            }
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
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        g[a].push_back(pair<int, int>(b, c));
//        g[b].push_back(pair<int, int>(a, c));
    }
    dijkstra(1);
    if(dist[n] != INF) cout << dist[n] << ' ' << dp[n] << ' ' << mi[n] << ' ' << ma[n];
    else cout << -1;
    return 0;
}
