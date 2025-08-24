#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 3;

int n, k, q, a[maxn], ma;
long long Ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    for(int r = 1; r <= n; r++){
        ma = max(ma, a[r]);
        if(ma <= q){
            if(r - l + 1 >= k) Ans += r - l - k + 2;
        }
        else{
            l = r + 1;
            ma = 0;
        }
    }
    cout << Ans;
    return 0;
}
