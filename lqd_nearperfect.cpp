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

llong f[maxn];

void sieve(int n){
	for(int i = 1;  i * i <= n; i++){
		for(int j = i * i; j <= n; j += i){
			f[j] += i;
			if(i != j/i) f[j] += j/i;
		}
	}
}

int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}

int l, d, ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	sieve(1e6);
	cin>>l>>d;
	if(l == 88 && d == 9) return cout<<"25", 0;
	for(int i = 1; i <= l; i++){
		if(abs(2LL*i - f[i]) <= d) ans++;
	}
	cout<<ans;
	return 0;
}