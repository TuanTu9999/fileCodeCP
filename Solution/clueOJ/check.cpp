#include <bits/stdc++.h>

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

#define int long long

inline int random(int l, int r) {
    return rd() % (r - l + 1) + l;
}

inline void maketest() {
    ofstream cout("INOUT.INP");

    int n = random(1, 300), w = random(1, 1e9);
    cout << n << ' ' << w << ' ' << 0 << '\n';
    for (int i = 1; i <= n; i++) {
        cout << random(1, w) << ' ' << 0 << '\n';
    }

    cout.close();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0); cout.tie(0);

    int tt = 100;
    while (tt--) {
        maketest();
        system("./thhv24_jump24");
        system("./thhv24_jump24_trau");
        if (system("diff INOUT.OUT INOUT.ANS")) {
            cerr << "pass\n";
        } else {
            cerr << "wa\n";
            break;
        }
    }
}
