#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, a[maxn];
long long pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        cout << (pre[n] - pre[i]) - 1LL * a[i] * (n - i) + 1LL * a[i] * i - pre[i] << ' ';
    }
    return 0;
}
