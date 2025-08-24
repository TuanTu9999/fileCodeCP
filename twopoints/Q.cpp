#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, k, a[maxn], c[maxn], Ans;

bool check(int len){
    int l = 1;
    memset(c, 0, sizeof c);
    for(int i = 1; i <= len; i++){
        c[a[i]]++;
        if(c[a[len]] + k >= len) return 1;
    }

    for(int r = len + 1; r <= n; r++, l++){
        c[a[r]]++;
        c[a[l]]--;
        if(c[a[r]] + k >= len) return 1;
    }
    return 0;
}

void process(){
    Ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            Ans = max(Ans, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << Ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    int T; cin >> T;
    while(T--) process();
    return 0;
}
