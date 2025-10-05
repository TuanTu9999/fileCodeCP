#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n;
int a[maxn], cnt[maxn];

string bin(int mask) {
    string s = "";
    for (int i = n - 1; i >= 0; i--) {
        if (mask & (1 << i)) s += '1';
        else s += '0';
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    long long Ans = 0;
    for (int mask = 1; mask <= n; mask++) {
        Ans += 1ll * cnt[mask] * (cnt[mask] - 1);
        Ans += 1ll * cnt[mask] * cnt[mask ^ 1];
    }

    cout << (Ans >> 1);
    
    return 0;
}
