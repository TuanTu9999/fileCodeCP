#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;
const int inf = 0x3f3f3f3f;

int n, m, S, T;
int dist[maxn];
vector<int> g[maxn];

void BFS(int u){
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    queue<int> q;
    while(q.size()){
        u = q.front();
        q.pop();
        for(int x : g[u]){
            if(dist[x] > dist[u] + 1){
                dist[x] = dist[u] + 1;
                q.push(x);
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
    cin >> n >> m >> S >> T;
    for(int i = 1; i <= m; i++){
        int k, l; cin >> k >> l;
        g[k].push_back(l);
    }
    BFS(S);
    if(dist[T] != inf) cout << dist[T];
    else cout << -1;
    return 0;
}
