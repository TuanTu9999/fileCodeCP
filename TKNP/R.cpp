#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 3;

int n, k, a[maxn], Ans, var[maxn];
vector<pair<int, int>> pos;

bool check(int f){
    int tmp = k;
    pos.clear();
    for(int i = 1; i <= n; i++) var[i] = a[i] % f;
    int d = 0;
    for(int i = 1; i <= n + 1; i++){
        if(var[i] > 0) d++;
        else{
            if(d) pos.push_back(pair<int, int>(i, d));
            d = 0;
        }
    }
    tmp = 0;
    int l = 0;
    for(const auto& x : pos){
        if(l) tmp += x.second + ((x.first - x.second) - l + 1);
        else tmp += x.second;
        l = x.first + 1;
    }
    return (tmp <= k);
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
    if(n == k + 1){
        cout << max(a[1], a[n]);
        return 0;
    }
    int l = 1, r = 1e9;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            Ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << Ans;
    return 0;
}
