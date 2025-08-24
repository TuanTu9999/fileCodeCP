#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 3;

int n, m, g[maxn][maxn];

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
        int a, b; cin >> a >> b;
        g[a][b]++;
        g[b][a]++;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
