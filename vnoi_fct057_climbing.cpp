#include <bits/stdc++.h>
#define pii pair<int, int>
#define ALL(x) x.begin(), x.end()

using namespace std;

const int maxn = 1000010;

int n, m, c;
int a[maxn];
int Min[maxn], Max[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];

    deque<int> dqMin, dqMax;
    for (int i = 1; i <= n; i++) {
        if (dqMin.size() && dqMin.front() <= i - m) dqMin.pop_front();
        while (dqMin.size() && a[dqMin.back()] >= a[i]) {
            dqMin.pop_back();
        }
        dqMin.push_back(i);

        if (dqMax.size() && dqMax.front() <= i - m) dqMax.pop_front();
        while (dqMax.size() && a[dqMax.back()] <= a[i]) {
            dqMax.pop_back();
        }
        dqMax.push_back(i);

        Min[i] = a[dqMin.front()];
        Max[i] = a[dqMax.front()];
    }

    vector<int> Ans;
    for (int i = m; i <= n; i++) {
        if (Max[i] - Min[i] <= c) {
            Ans.push_back(i - m + 1);
        }
    }

    if (Ans.empty()) {
        cout << "NONE";
    } else {
        for (const int &x : Ans) cout << x << '\n';
    }
    
    return 0;
}
 
