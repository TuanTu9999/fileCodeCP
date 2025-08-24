#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 3;
int n, a[maxn], fL[maxn], fR[maxn], L[maxn], R[maxn], ans;

void buildL(){
    int res = 0;
    for(int i = 1; i <= n; i++){
        int j = lower_bound(fL + 1, fL + res + 1, a[i]) - fL;
        L[i] = j - 1;
        res = max(res, j);
        fL[j] = a[i];
    }
}

void buildR(){
    int res = 0;
    for(int i = n; i > 0; i--){
        int j = lower_bound(fR + 1, fR + res + 1, a[i]) - fR;
        R[i] = j - 1;
        res = max(res, j);
        fR[j] = a[i];
    }
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
    buildL();
    buildR();
    for(int i = 2; i <= n; i++){
//        cout << L[i] << ' ';
        L[i] = max(L[i], L[i - 1]);
    }
//    cout << '\n';
    for(int i = n - 1; i > 0; i--){
//        cout << R[i] << ' ';
        R[i] = max(R[i], R[i + 1]);
    }
//    cout << '\n';
    for(int i = 2; i < n; i++){
        ans = max(ans, 2 * min(L[i], R[i]) + 1);
    }
    cout << ans;
    return 0;
}
