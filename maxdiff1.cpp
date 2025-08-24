#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 10;

int n, a[maxn];
long long pre[maxn], suf[maxn], Ans = -1e18;
priority_queue<int> qMax;
priority_queue<int, vector<int>, greater<int>> qMin;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME ""
    if(fopen(FILENAME".INP", "r")) {
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= 3 * n; i++) cin >> a[i];

    for(int i = 1; i <= 3 * n; i++) {
        if(qMin.size() < n) {
            pre[i] = pre[i - 1] + a[i];
            qMin.push(a[i]);
        }
        else {
            int mi = qMin.top();
            if(mi < a[i]) {
                pre[i] = pre[i - 1] + a[i] - mi;
                qMin.pop();
                qMin.push(a[i]);
            }
            else pre[i] = pre[i - 1];
        }
    }

    for(int i = 3 * n; i > 0; i--) {
        if(qMax.size() < n) {
            suf[i] = suf[i + 1] + a[i];
            qMax.push(a[i]);
        }
        else {
            int ma = qMax.top();
            if(ma > a[i]) {
                suf[i] = suf[i + 1] + a[i] - ma;
                qMax.pop();
                qMax.push(a[i]);
            }
            else suf[i] = suf[i + 1];
        }
    }

    for(int i = n; i <= 2 * n; i++) {
        Ans = max(Ans, pre[i] - suf[i + 1]);
    }
    cout << Ans;
    return 0;
}
