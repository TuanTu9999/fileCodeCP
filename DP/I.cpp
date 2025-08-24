#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;
int n, a[maxn], f[maxn], ans;

bool check(int a){
    if(a == 0) return 0;
    int t = (int)sqrt(a);
    return (t * t == a);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    f[1] = check(a[1]);
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        for(int j = i - 1; j > 0 && abs(i - j) <= 10; j--){
            if(check(abs(a[i] - a[j]))){
                f[i] = max(f[i], f[j] + 1);
            }
        }
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}
