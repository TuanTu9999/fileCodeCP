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

#define maxn ((int)(5e5) + 10)
#define LOG (int)(31 - __builtin_clz(maxn))
const int MOD = 1e9 + 7;
// #define ONLINE_JUDGE

int n, m;
int x[maxn];

struct car {
    int f, s, c, r;
} b[maxn];

namespace sub1 {
	bool checkSub() {
		return m == 1;
	}

    bool check(long long d, int f, int s, int r) {
        int lastStop = f;
        int cntStop = 0;
        
        while(lastStop < s) {
            long long tarDist = x[lastStop] + d;
            
            int nextStop = upper_bound(x + lastStop + 1, x + s + 1, tarDist) - x - 1;
            if (nextStop == lastStop) return false;
            
            lastStop = nextStop;
            cntStop++;
        }
        
        return cntStop <= r + 1;
    }

    void process() {
        int f = b[1].f, s = b[1].s, c = b[1].c;

        long long l = 0, r = x[s] - x[f], Ans = 0;

        while (l <= r) {
            long long mid = l + r >> 1;
            if (check(mid, f, s, b[1].r)) {
                Ans = mid;
                r = mid - 1;
            } else {
            	l = mid + 1;
            }
        }

        cout << Ans * c;
    }
}

namespace sub2 {
	long long calc(int pos) {
		int f = b[pos].f, s = b[pos].s, c = b[pos].c;

        long long l = 0, r = x[s] - x[f], res = 0;

        while (l <= r) {
            long long mid = l + r >> 1;
            if (sub1::check(mid, f, s, b[pos].r)) {
                res = mid;
                r = mid - 1;
            } else {
            	l = mid + 1;
            }
        }

        return res * c;
	}

    void process() {
    	long long Ans = 0;
    	for (int i = 1; i <= m; i++) {
    		maximize(Ans, calc(i));
    	}

    	cout << Ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
#define FILENAME "DaiLy"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".OUT", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= m; i++) cin >> b[i].f >> b[i].s >> b[i].c >> b[i].r;
    
    if (sub1::checkSub()) sub1::process();
	else sub2::process();

    return 0;
}