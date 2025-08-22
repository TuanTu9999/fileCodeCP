#include <bits/stdc++.h>

using namespace std;

long long n;

namespace sub1 {
    inline bool checkSub() {
        return n <= 10;
    }

    inline void process() {
        if (n < 9) cout << n + 1;
        else cout << 11;
    }
}

namespace sub3 {
    inline bool checkSub() {
        return n <= 1000000;
    }

    long long Ans;

    void process() {
        for (int i = 1; i <= 2 * n; i++) {
            string s = "";
            int curI = i;
            long long num = 0;
            while (curI) {
                num = num * 10 + (curI % 10);
                curI /= 10;
            }
            if (num > n) {
                Ans = i;
                break;
            }
        }

        cout << Ans;
    }
}

namespace subAC {
    void process() {
        string Sn = "";
        long long curN = n;
        while (curN) {
            Sn += (char)(curN % 10 + '0');
            curN /= 10;
        }
        int len = (int)Sn.size();
        reverse(Sn.begin(), Sn.end());    
       
        int cnt = 0;
        for (char c : Sn) {
            cnt += (c - '0') % 10 != 0;
        }

        if (cnt == 1) {
            cout << 1;
            for (int i = 1; i < len - 1; i++) cout << 0;
            cout << Sn[0];
            return;
        }

        if (Sn[0] != '9') {
            cout << 1;
            for (int i = 2; i < len; i++) cout << 0;
            cout << (char)(Sn[0] + 1);
            return;
        }

        cnt = 0;
        int idx = 0;
        for (int i = len - 1; i >= 0; i--) {
            if (Sn[i] != '9') {
                cnt++;
                idx = i;
            }
        }
        if (cnt) {
            if (idx == len - 1 && cnt == 1) {
                cout << (char)(Sn.back() + 1);
                for (int i = 1; i < len; i++) cout << 9;
            } else {
                cout << 1;
                for (int i = 1; i < len - idx - 1; i++) {
                    cout << 0;
                }
                cout << (char)(Sn[idx] + 1);
                for (int i = idx; i > 0; i--) {
                    cout << 9;
                }
            }
        } else {
            cout << 1;
            int idx = 0;
            for (int i = 0; i < len; i++) {
                if (Sn[i] == '9') {
                    idx = i;
                    break;
                }
            }
            cout << 1;
            for (int i = len - 2; i > idx + 1; i--) cout << 0;
            cout << (char)(Sn[idx + 1] + 1);
            for (int i = idx; i >= 0; i--) cout << 9;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    // freopen("INOUT.INP", "r", stdin);
    // freopen("INOUT.OUT", "w", stdout);

    cin >> n;
    if (sub1::checkSub()) sub1::process();
    else subAC::process();

    return 0;
}
