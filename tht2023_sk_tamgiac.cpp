#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 10;

int n, pos[maxn];
long long cnt1, cnt2;

void process() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> pos[i];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    int T; cin >> T;
    while(T--) {
        process();
    }

    return 0;
}
