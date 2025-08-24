#include <bits/stdc++.h>

using namespace std;

const int maxn = 1003;

bool kt[maxn], vis[maxn];
vector<int> prime;
long long dp[maxn];

void sieve(int Ln){
    for(int i = 2; i * i <= Ln; i++){
        if(!kt[i]){
            for(int j = i * i; j <= Ln; j += i)
                kt[j] = 1;
        }
    }
    for(int i = 2; i <= Ln; i++)
        if(!kt[i]) prime.push_back(i);
}

void init(){
    sieve(1000);
    vis[0] = 1;
    for(int sl = 1; sl <= 2; sl++){
        for(int pr : prime){
            for(int S = 1000; S >= pr; S--){
                if(vis[S - pr]){
                    dp[S] = max(dp[S], dp[S - pr] + 1);
                    vis[S] = 1;
                }
            }
        }
    }
    dp[1] = 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define FILENAME "BAI4"
    if(fopen(FILENAME".INP", "r")){
        freopen(FILENAME".INP", "r", stdin);
        freopen(FILENAME".OUT", "w", stdout);
    }
    init();
    int n;
    while(cin >> n)
        cout << dp[n] << '\n';
    return 0;
}