#include <bits/stdc++.h>

#define int long long

using namespace std;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
    return rd() % (r - l + 1) + l;
}

void makeTest() {
	ofstream cout("INOUT.INP");
	int n = random(2, 1e5);
	for (int i = 1; i <= n; i++) {
		cout << (char)(random('a', 'z'));
	}
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // system("chmod +x test trau");

    for (int i = 1; i <= 100; i++) {
        makeTest();
        system("./COUNTSTR");
        system("./trau");
        if (system("diff INOUT.OUT INOUT.ANS")) {
            cerr << i << " WRONG\n";
            break;
        }
        cerr << i << " PASSED\n";
    }

    return 0;
}