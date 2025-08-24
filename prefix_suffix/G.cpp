#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

int n, p, q, r, ans;
long long pre[maxn];

int binary(int maxp, long long target){
    int l = 1, r = maxp;
    while(l <= r){
        int mid = (l + r) / 2;
        long long tmp = pre[maxp] - pre[mid - 1];
        if(tmp == target) return mid;
        else if(tmp > target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> p >> q >> r;
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    for(int i = 1; i <= n; i++){
        int z = binary(i, r);
        if(z != -1){
            int y = binary(z - 1, q);
            if(y != -1){
                int x = binary(y - 1, p);
                if(x != -1) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
