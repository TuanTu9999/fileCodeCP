#include <bits/stdc++.h>
#define int long long

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    return rd() % (r - l + 1) + l;
}

// g++ -std=c++17 -g check1.cpp -o check && ./check

void makeTest() {
    ofstream cout("INOUT.INP");

    int n = random(1, 40), m = random(1, 40);
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= m; i++) {
            cout << random(1, 2) << ' ';
        }
        cout << '\n';
    }

    cout.close();
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // system("chmod +x test trau");

    for (int i = 1; i <= 10; i++) {
        makeTest();
        system("./TABLE");
        system("./TABLE_trau");
        if (system("diff INOUT.OUT INOUT.ANS")) {
            cerr << i << " WRONG\n";
            break;
        }
        cerr << i << " PASSED\n";
    }

    return 0;
}
 