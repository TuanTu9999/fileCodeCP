#include <bits/stdc++.h>
using namespace std;

#define int long long

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int random(int l, int r) {
	return rd() % (r - l + 1) + l;
}

void makeTest() {
	ofstream cout("BAI4.INP");
	int n = 1e5, m = 1e5;
	for (int i = 1; i <= n; i++) cout << (char)(random('a', 'z'));
	cout << '\n';
	for (int i = 1; i <= m; i++) cout << (char)(random('a', 'z'));	

	cout.close();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tt = 1;
    while (tt--) {
    	makeTest();

    	system("./BAI4");
	    system("./BAI4_trau");

    	if (system("diff BAI4.OUT BAI4.ANS")) {
    		cerr << "WA\n";
    		break;
    	} else {
    		cerr << "Pass\n";
    	}
    }

    return 0;
}