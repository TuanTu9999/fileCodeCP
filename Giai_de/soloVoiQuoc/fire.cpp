#include <bits/stdc++.h>
// https://drive.google.com/file/d/1_DM932eatpKRTmC6knv72YmFC7f51yNH/view?usp=sharing

#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define COMP(x) x.resize(unique(all(x)) - x.begin())
template<typename T>
inline bool maximize(T &res, const T &val) {
    if (res < val) return res = val, 1;
    return 0;
}
template<typename T>
inline bool minimize(T &res, const T &val) {
    if (res > val) return res = val, 1;
    return 0;
}

using namespace std;

#define maxn (int)(5e5 + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, k;
int h[maxn], t[maxn], L[maxn], R[maxn];
long long pre[maxn];

bool check(long long T) {
    vector<int> dp(n + 1, 0);

    int l = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        while (l < n && pre[l] < pre[i - 1] - T)
            ++l;
        while (r <= n && pre[r] <= pre[i - 1] + T)
            ++r;

        maximize(dp[l + 1], r);
    }

    for (int i = 1; i <= n; i++)
        maximize(dp[i], dp[i - 1]);

    int group = 0, pos = 0;
    while (pos < n) {
        group++;
        if (dp[pos + 1] == 0) return 0;
        pos = dp[pos + 1];
    }

    return group <= k;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < n; i++) cin >> t[i];

    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + t[i];

    vector<int> st;
    for (int i = 1; i <= n; i++) {
        while (st.size() && h[st.back()] < h[i]) 
            st.pop_back();
        L[i] = st.size() ? st.back() : 1;
        st.emplace_back(i);
    }
    st.clear();
    for (int i = n; i > 0; i--) {
        while (st.size() && h[st.back()] < h[i]) 
            st.pop_back();
        R[i] = st.size() ? st.back() : n;
        st.emplace_back(i);
    }

    long long l = 1, r = pre[n - 1], Ans = -1;
    while (l <= r) {
        long long mid = l + r >> 1;
        if (check(mid)) {
            Ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << Ans;

    return 0;
}
