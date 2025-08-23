#include <bits/stdc++.h>

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

#define maxn ((int)(1e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

// link code sinh Answer: https://github.com/TuanTu9999/fileCodeCP/blob/main/Giai_de/soloVoiQuoc/23_08_2025/trau_sublucas.cpp
string Ans[] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "96046080412173", "7288082074054989", "7288082074054989", "7288082074054989", "7288082074054989", "251104685236025755", "251104685236025755", "251104685236025755", "251104685236025755", "251104685236025755", "251104685236025755"};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "INOUT"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int tt;
    cin >> tt;
    while (tt--) {
    	int n;
    	cin >> n;
    	cout << Ans[n] << '\n';
    }

    return 0;
}
