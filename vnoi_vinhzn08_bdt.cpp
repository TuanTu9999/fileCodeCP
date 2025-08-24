#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, m, ans[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        ans[a]++;
        ans[b]++;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
    return 0;
}
