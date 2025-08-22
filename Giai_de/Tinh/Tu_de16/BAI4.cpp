#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    string ans = "";
    vector<int> pos1, pos2;

    for (int i = 0; i < n; ++i) {
        pos1.push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        pos2.push_back(i);
    }

    while (true) {
        bool extended = false;
        char next_char = 0;
        vector<int> next_pos1, next_pos2;

        for (char c = 'z'; c >= 'a'; --c) {
            vector<int> current_pos1, current_pos2;
            for (int p : pos1) {
                if (p + ans.length() < n && s1[p + ans.length()] == c) {
                    current_pos1.push_back(p);
                }
            }
            for (int p : pos2) {
                if (p + ans.length() < m && s2[p + ans.length()] == c) {
                    current_pos2.push_back(p);
                }
            }

            if (!current_pos1.empty() && !current_pos2.empty()) {
                extended = true;
                next_char = c;
                next_pos1 = current_pos1;
                next_pos2 = current_pos2;
                break;
            }
        }

        if (extended) {
            ans += next_char;
            pos1 = next_pos1;
            pos2 = next_pos2;
        } else {
            break;
        }
    }

    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #ifndef ONLINE_JUDGE
    #define FILENAME "BAI4"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
    #endif

    solve();

    return 0;
}