#include <bits/stdc++.h>

using namespace std;

const int maxn = 53;
int n, x, a[maxn];
long double dp[maxn];

long double f(long double m, int i, int j){
    return 1.0 * m * (1.0 * a[i] / a[j]) - 2.0 * m / 100;
}

void solve(){
    cin >> n >> x;
    dp[0] = x;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        /// khong giao dich
        dp[i] = dp[i - 1];
        /*
         Thực hiện giao dịch bán ở ngày thứ i và mua ở ngày thứ j (j<i) với số tiền có
         được từ ngày j−1, vì ta sẽ mua hết tiền vào Bitcoin nên các ngày [j+1;i−1] sẽ không có
         giao dịch nào và số tiền có được tại ngày thứ i là từ việc bán Bitcoin
        */
        for(int j = 1; j < i; j++) dp[i] = max(dp[i], f(dp[j - 1], i, j));
    }
    cout << fixed << setprecision(5) << dp[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    int q; cin >> q;
    while(q--) solve();
    return 0;
}
