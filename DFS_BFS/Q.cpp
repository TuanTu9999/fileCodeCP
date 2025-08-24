#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;
const int INF = 0x3f3f3f3f;

int n, x, y, a[maxn][maxn], dist[maxn];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
vector<int> g[maxn * maxn];

void build() {
    int cL = 1, cR = n, lU = 1, lD = n, num = 1;

    while(num <= n * n){
        for(int i = cL; i <= cR; i++)
            a[lU][i] = num++;
        lU++;

        for(int i = lU; i <= lD; i++)
            a[i][cR] = num++;
        cR--;

        for (int i = cR; i >= cL; i--)
            a[lD][i] = num++;
        lD--;

        for(int i = lD; i >= lU; i--)
            a[i][cL] = num++;
        cL++;
    }
}

void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 0; k < 4; k++){
                int x = i + dx[k], y = j + dy[k];
                if(x > 0 && x <= n && y > 0 && y <= n && __gcd(a[i][j], a[x][y]) == 1){
                    g[a[i][j]].push_back(a[x][y]);
                    g[a[x][y]].push_back(a[i][j]);
                }
            }
        }
    }
}

void DFS(int u){
    memset(dist, 0x3f, sizeof dist);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        for(int v : g[u]){
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
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
    int T; cin >> T;
    while(T--){
        cin >> n >> x >> y;
        build();
        for(int i = 1; i <= n * n; i++) g[i].clear();
        init();
        DFS(x);
        if(dist[y] != INF) cout << dist[y] << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
