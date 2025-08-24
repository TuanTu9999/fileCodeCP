#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 3;

bool kt[maxn];
vector<int> prime;
long long ans;
int n, a[maxn];

void sieve(int n){
    kt[1] = kt[0] = 1;
    for(int i = 2; i * i <= n; i++){
        if(!kt[i]){
            for(int j = i * i; j <= n; j += i) kt[j] = 1;
        }
    }
    for(int i = 2; i <= n; i++) if(!kt[i]) prime.push_back(i);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    sieve(1e6 + 3);
    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(!kt[x]) continue;
        int l = lower_bound(prime.begin(), prime.end(), x) - prime.begin();
        int r = upper_bound(prime.begin(), prime.end(), x) - prime.begin() - 1;
        if(r < 0) r = 0;
        if(l >= (int)prime.size()) l = prime.size() - 1;
        ans += min(abs(prime[l] - x), abs(prime[r] - x));
    }
    cout << ans;
    return 0;
}
