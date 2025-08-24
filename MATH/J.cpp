#include <bits/stdc++.h>

using namespace std;

long long n;
vector<long long> divi;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    for(long long i = 1; i * i <= n; i++){
        if(n % i == 0){
            divi.push_back(i);
            if(i * i != n) divi.push_back(n / i);
        }
    }
    sort(divi.begin(), divi.end());
    for(long long x : divi) cout << x << ' ';
    return 0;
}
