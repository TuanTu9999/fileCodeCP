#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
bool kt[maxn];
int ans, n;
vector<int> prime;

void sieve(int n){
    kt[0] = kt[1] = 1;
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
    sieve(sqrt(n) + 2);
    for(int x : prime){
        if(1LL * x * x > n) break;
        ans++;
    }
    cout << ans;
    return 0;
}
