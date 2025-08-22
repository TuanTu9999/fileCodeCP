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

#define maxn ((int)300)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = ((int)(1e9) + 696969);
// #define ONLINE_JUDGE

string s;

void process() {
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] - '0' & 1) {
        ++cnt;
    }

    if (cnt < 2) {
        cout << 0 << '\n';
        return;
    }

    while (s.size() && ((s.back() - '0') % 2 == 0)) 
        s.pop_back();

    if (cnt & 1) {
        vector<string> memo;
        string cur = "";
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) if (s[j] - '0' & 1) {
                memo.emplace_back(cur + s.substr(i + 1, j - i + 1));
            }   
            cur += s[i];
        }
        for (string &x : memo) {
            reverse(all(x));
            while (x.size() && x.back() == '0') x.pop_back();
            reverse(all(x));

            while (x.size() && ((x.back() - '0') % 2 == 0)) x.pop_back();
        }

        sort(all(memo), [&](const string &x, const string &y) {
            if (x.size() != y.size()) return x.size() > y.size();
            return x > y;
        });
        
        for (const string &x : memo) {
            long long sum = 0;
            for (char c : x) sum += c - '0';
            // cerr << x << ' ' << sum << '\n';
            if (sum % 2 == 0) {
                s = x;
                break;
            }
        }
    }

    reverse(all(s));
    while (s.size() && s.back() == '0') s.pop_back();
    reverse(all(s));

    cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "BAI3"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    int tt; cin >> tt;
    while (tt--) {
        process();
    }

    return 0;
}