#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, x, a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    while(l < r){
        if(a[l] + a[r] == x) break;
        else if(a[l] + a[r] < x) l++;
        else r--;
    }
    if(a[l] + a[r] == x && l != r) cout << l << ' ' << r;
    else cout << "No solution";
    return 0;
}
