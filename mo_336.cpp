#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;

int n, k, a[maxn];
deque<int> dq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        if(dq.size() && dq.back() <= i - k) dq.pop_back();
        while(dq.size() && a[i] <= a[dq.front()])
            dq.pop_front();

        dq.push_front(i);
        if(i >= k) cout << a[dq.back()] << ' ';
    }
    return 0;
}
