#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
string S1, S2;
string T; // S1 + sep + S2 + terminator

// SA doubling O(n log n)
vi build_sa(const string &s) {
    int n = s.size(), k = 1;
    vi sa(n), r(n), tmp(n);
    for (int i = 0; i < n; ++i) sa[i] = i, r[i] = (unsigned char)s[i];
    auto cmp = [&](int a, int b)->bool{
        if (r[a] != r[b]) return r[a] < r[b];
        int ra = a + k < n ? r[a + k] : -1;
        int rb = b + k < n ? r[b + k] : -1;
        return ra < rb;
    };
    for ( ; ; k <<= 1) {
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i) {
            tmp[sa[i]] = tmp[sa[i-1]] + (cmp(sa[i-1], sa[i]) ? 1 : 0);
        }
        for (int i = 0; i < n; ++i) r[i] = tmp[i];
        if (r[sa[n-1]] == n-1) break;
    }
    return sa;
}

// Kasai LCP (between adjacent suffixes in SA order)
vi build_lcp(const string &s, const vi &sa) {
    int n = s.size();
    vi rank(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    vi lcp(max(0,n-1));
    int h = 0;
    for (int i = 0; i < n; ++i) {
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && s[i+h] == s[j+h]) ++h;
        lcp[rank[i]-1] = h;
        if (h) --h;
    }
    return lcp; // length n-1, lcp[i] = lcp(sa[i], sa[i+1])
}

// RMQ sparse table for lcp queries between SA indices (rank indices)
struct RMQ {
    int n, LOG;
    vector<vector<int>> st;
    vector<int> lg;
    RMQ() {}
    RMQ(const vi &a) {
        n = a.size();
        lg.assign(n+1, 0);
        for (int i = 2; i <= n; ++i) lg[i] = lg[i/2] + 1;
        LOG = lg[n] + 1;
        st.assign(LOG, vector<int>(n));
        if (n==0) return;
        for (int i = 0; i < n; ++i) st[0][i] = a[i];
        for (int k = 1; k < LOG; ++k) {
            for (int i = 0; i + (1<<k) <= n; ++i) {
                st[k][i] = min(st[k-1][i], st[k-1][i + (1<<(k-1))]);
            }
        }
    }
    int query(int l, int r) { // inclusive l..r
        if (l > r) swap(l,r);
        if (l==r) return INT_MAX; // not used
        int len = r - l + 1;
        int k = lg[len];
        return min(st[k][l], st[k][r - (1<<k) + 1]);
    }
};

int lcp_between_suffixes_using_sa(const vi &rank, RMQ &rmq, int a, int b) {
    if (a == b) return (int)T.size() - a;
    int ra = rank[a], rb = rank[b];
    if (ra > rb) swap(ra, rb);
    // lcp array index corresponds to [ra .. rb-1]
    return rmq.query(ra, rb-1);
}

// compare two substrings (pos1,len1) and (pos2,len2) lexicographically
// return true if first > second
bool substr_greater(int p1, int l1, int p2, int l2, const vi &rank, RMQ &rmq) {
    int common = lcp_between_suffixes_using_sa(rank, rmq, p1, p2);
    int mn = min(l1, l2);
    if (common >= mn) {
        if (l1 != l2) return l1 > l2; // longer is larger
        return false; // equal
    } else {
        char c1 = T[p1 + common], c2 = T[p2 + common];
        return c1 > c2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define FILENAME "BAI4"
    freopen(FILENAME ".INP", "r", stdin);
    freopen(FILENAME ".ANS", "w", stdout);


    if (!(cin >> S1)) return 0;
    cin >> S2;
    // choose separators not in input: use chars with small codes
    char sep = char(1), term = char(0);
    T = S1 + sep + S2 + term;
    int n = T.size();
    vi sa = build_sa(T);
    vi lcp = build_lcp(T, sa); // size n-1

    // build rank array (pos -> rank in SA)
    vi rank(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;

    // build RMQ on lcp (size n-1)
    RMQ rmq(lcp);

    int split = (int)S1.size(); // positions < split are in S1; position == split is sep; positions > split and < split+1+S2.size() are in S2
    auto owner = [&](int pos)->int{
        if (pos < 0 || pos >= n) return -1;
        if (pos < split) return 1; // S1
        if (pos == split) return 0; // separator
        if (pos > split && pos < split + 1 + (int)S2.size()) return 2; // S2
        return -1;
    };

    bool found = false;
    int best_pos = -1, best_len = 0;

    for (int i = 0; i + 1 < n; ++i) {
        int a = sa[i], b = sa[i+1];
        int oa = owner(a), ob = owner(b);
        if ((oa == 1 && ob == 2) || (oa == 2 && ob == 1)) {
            int L = lcp[i]; // common prefix length
            if (L <= 0) continue;
            // candidate substring content is T.substr(a, L) (same as from b)
            // choose representative starting pos = a (or b) — content equal
            int cand_pos = a;
            int cand_len = L;
            if (!found) {
                found = true;
                best_pos = cand_pos; best_len = cand_len;
            } else {
                if (substr_greater(cand_pos, cand_len, best_pos, best_len, rank, rmq)) {
                    best_pos = cand_pos; best_len = cand_len;
                }
            }
        }
    }

    if (!found) {
        cout << -1 << '\n';
    } else {
        // substring might contain separator if we took position crossing, but our owner check avoided sep.
        cout << T.substr(best_pos, best_len) << '\n';
    }

    return 0;
}
