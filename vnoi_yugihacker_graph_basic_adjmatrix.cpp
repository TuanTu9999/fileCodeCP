#include <bits/stdc++.h>

using namespace std;

int n, m, g[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
	for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        g[u][v]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << g[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
