#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, k, a[maxn];
double Ans, pre[maxn];

bool check(double preAns){
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i] - preAns;
    double mi = 0.0;
    for(int i = k; i <= n; i++){
        if(pre[i] >= mi) return 1;
        mi = min(mi, pre[i - k + 1]);
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    double l = *min_element(a + 1, a + n + 1), r = *max_element(a + 1, a + n + 1);
    while(r - l >= 1e-3){
        double mid = (l + r) / 2.0;
        if(check(mid)){
            Ans = mid;
            l = mid;
        }
        else r = mid;
    }
    cout << fixed << setprecision(3) << Ans;
    return 0;
}
