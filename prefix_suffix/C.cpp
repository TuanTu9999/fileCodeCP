#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, k, a[maxn], pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        int l = 1, r = i, ans = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(pre[i] - pre[mid - 1] <= k){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
