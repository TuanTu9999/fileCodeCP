#include <bits/stdc++.h>
#define llong            long long
#define el               cout << '\n'
#define pii              pair<int, int>
#define fi               first
#define se               second
#define veci             vector<int>
#define mapii            map<int, int>
#define pb               push_back

using namespace std;

const int maxn = 1e6 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int n, a[maxn], q, t[4 * maxn];
vector<llong> b;
llong ans, pre[maxn];

llong query(int id, int l, int r, int st, int en){
	if(r < st || en < l) return 0;
	if(st <= l && r <= en) return t[id];
	int m = (l + r) / 2;
	return query(id*2, l, m, st, en) + query(id*2+1, m+1, r, st, en);
}

void ud(int id, int l, int r, int pos, int val){
    if(pos < l || r < pos) return;
    if(l == r){
        t[id] += val;
        return;
    }
    int m = (l + r) / 2;
    ud(id*2, l, m, pos, val);
    ud(id*2+1, m+1, r, pos, val);
    t[id] = t[id*2] + t[id*2+1];
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> q;
	for(int i = 0; i < n; i++){
		pre[i + 1] = pre[i] + a[i] - q;
		b.push_back(pre[i + 1]);
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	int tmp1 = lower_bound(b.begin(), b.end(), 0) - b.begin() + 1;
	ud(1, 1, n + 1, tmp1, 1);
	for(int i = 1; i <= n; i++){
		int idx = lower_bound(b.begin(), b.end(), pre[i]) - b.begin() + 1;
		ans += query(1, 1, n + 1, 1, idx);
		ud(1, 1, n + 1, idx, 1);
	}
	cout << ans;
	return 0;
}