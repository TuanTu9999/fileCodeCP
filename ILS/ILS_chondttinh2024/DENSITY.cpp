#include <bits/stdc++.h>
#define debug(a) cerr << (a) << ' '
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define MASK(x) ((1LL) << (x))
#define BIT(x, i) (((x) >> (i)) & (1LL))
#define eb emplace_back
#define pb push_back

// #pragma GCC             optimize("Ofast")
// #pragma GCC             optimize("O3")
// #pragma GCC             optimize("unroll-loops")
// #pragma GCC             target("avx,avx2,fma")

using namespace std;

template<typename T>
bool maximize(T &res, const T &val) {
    if (res < val) {
        res = val;
        return 1;
    }
    return 0;
}

template<typename T>
bool minimize(T &res, const T &val) {
    if (res > val) {
        res = val;
        return 1;
    }
    return 0;
}

const int maxn = 1e6 + 10;
const int MOD = 1e9 + 7;
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define LOG 20

long long binPow(long long a, long long e, long long mod) {
    long long res = 1;
    a %= mod;
    while (e) {
        if (e & 1) res = res * a % mod;
        a = a * a % mod;
        e >>= 1;
    }
    return res;
}

bool miller(long long n, long long a) {
    if (a % n == 0) return 1;
    long long d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        ++s;
    }
    long long x = binPow(a, d, n);
    if (x == 1 || x == n - 1) return 1;
    for (int r = 1; r < s; r++) {
        x = x * x % n;
        if (x == n - 1) return true;
    }
    return 0;
}

bool isPrime(int n) {
    if (n < 2) return 0;
    static constexpr int smallP[] = {2,3,5,7,11,13,17,19,23,29,31,37};
    for (int p : smallP) {
        if (n == p) return 1;
        if (n % p == 0) return 0;
    }
    for (long long a : {2ll, 7ll, 61ll}) {
        if (!miller(n, a))
            return 0;
    }
    return 1;
}


signed main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define FILENAME "INOUT"
    if (fopen(FILENAME ".INP", "r")) {
        freopen(FILENAME ".INP", "r", stdin);
        freopen(FILENAME ".OUT", "w", stdout);
    }



    return 0;
}