#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, k;
long long pre[maxn], Ans;

bool check(long long nexAns) {
    for(int i = nexAns; i <= n; i++) {
        if(pre[i] - pre[i - nexAns] > k) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        pre[i] = pre[i - 1] + x;
    }
    int l = 0, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            Ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << Ans;
    return 0;
}
