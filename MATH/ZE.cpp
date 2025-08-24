#include <bits/stdc++.h>

using namespace std;

int n;

bool facDiv(int a){
    int num, cnt;
    num = cnt = 0;
    for(int i = 2; i * i <= a; i++){
        if(a % i == 0){
            num++;
            while(a % i == 0){
                cnt++;
                a /= i;
            }
        }
    }
    if(a > 1){
        num++;
        cnt++;
    }
    if(num == 2 && cnt == 2) return 1;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define NAME ""
    if(fopen(NAME".INP", "r")){
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
    cin >> n;
    while(n){
        if(facDiv(n)){
            cout << n;
            return 0;
        }
        n--;
    }
    return 0;
}
