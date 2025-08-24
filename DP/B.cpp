#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, h[maxn], f[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    f[2] = abs(h[1] - h[2]);
    for(int i = 3; i <= n; i++){
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << f[n];
    return 0;
}
