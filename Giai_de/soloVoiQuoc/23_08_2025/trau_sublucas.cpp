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

__int128 f[100], pre[100], Ans[100];

static inline void print(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << "-";
        x = -x;
    }
    string s;
    while (x > 0) {
        int digit = x % 10;
        s.push_back('0' + digit);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

long long pow(long long a, int b, int mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

bool isPrime(int n) {
    if (n == 2 || n == 3) return 1;
    if (n < 2 || n % 2 == 0 || n % 3 == 0) return 0;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    f[1] = 1;
    f[2] = 3;
    for (int i = 3; i <= 88; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    pre[1] = 1;
    for (int i = 2; i <= 88; i++) {
        pre[i] = pre[i - 1] ^ f[i];
    }

    for (int x = 1; x <= 88; x++) {
        for (int y = x + 1; y <= 88; y++) if (isPrime(x) && isPrime(y)) {
            if ((pow(y, y + 1, x * x) + pow(y + 1, y, x * x)) % (1ll * x * x) != 0)
                continue;
            for (int i = y; i <= 88; i++) {
                maximize(Ans[i], pre[y] ^ pre[x - 1]);
            }
        }
    }

    for (int i = 1; i <= 88; i++) {
        cout << '"';
        print(Ans[i]);
        cout << "\", ";
    }
    
    return 0;
}

