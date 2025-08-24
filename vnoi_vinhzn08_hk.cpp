#include <bits/stdc++.h>
#define llong long long
using namespace std;

llong n, ans;

bool check(llong k, llong n){
    llong res = 0, m = n;
    while(n >= k){
        res += k;
        n -= k;
        n -= n / 10;
    }
    res += n;
    return (2 * res >= m);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    llong l = 1, r = n;
    while(l <= r){
        llong mid = l + (r - l) / 2;
        if(check(mid, n)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
