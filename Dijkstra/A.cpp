#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, m;
long long dist[maxn];
vector<pair<int, long long>> g[maxn];
priority_queue<pair<long long, int>> q;

void dijkstra(int u){
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    q.push(pair<long long, int>(0LL, u));
    while(q.size()){
        u = q.top().second;
        int cost = q.top().first;
        q.pop();
        if(cost > dist[u]) continue;
        for(pair<int, long long> pos : g[u]){
            if(dist[pos.first] > dist[u] + pos.second){
                dist[pos.first] = dist[u] + pos.second;
                q.push(pair<long long, int>(dist[pos.first], pos.first));
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
    dijkstra(0);
    cout << dist[n];
    return 0;
}
