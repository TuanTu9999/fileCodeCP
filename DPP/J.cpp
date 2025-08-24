#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5 + 3;
int n, k, c[maxn];
long long ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    int inf = 2e5;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        ans += c[inf + x - k];
        c[inf + x]++;
    }
    cout << ans;
    return 0;
}
