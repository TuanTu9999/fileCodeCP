#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)5e5 + 3;
int n, q, a[maxn];
long long pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    cin >> q;
    while(q--){
        int k; cin >> k;
        int l = 0, r = n, ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(pre[mid] < 1LL * mid * k){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
