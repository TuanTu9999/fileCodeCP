#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 3;
int n, m, k, x, a[maxn], b[maxn], ans;

bool check(int preAns){
    int res = 0, tmp = k;
    int l = 1, r = max(1, m - n + 1);
    while(l <= n && r <= m){
        if(b[r] >= a[l]) res++;
        else if(tmp > 0){
            if(b[r] >= a[l] - x){
                res++;
                tmp--;
            }
        }
        l++;
        r++;
    }
    return (res >= preAns);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> m >> k >> x;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int l = 0, r = n;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
