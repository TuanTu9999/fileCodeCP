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

int a, b, c, d;

void rutgon(int& a, int& b){
    int k = __gcd(a, b);
    a /= k;
    b /= k;
}

void tong_hieu(int a, int b, int c, int d){
    int lcm = c * d / __gcd(c, d);
    a *= c/lcm;
    b *= d/lcm;
    rutgon(a, b);
    cout<<a + b<<'/'<<lcm<<' ';
    cout<<a - b<<'/'<<lcm<<' ';
}

void tich(int a, int b, int c, int d){
    a *= b;
    c *= d;
    rutgon(a, c);
    cout<<a<<'/'<<c<<' ';
}

void thuong(int a, int b, int c, int d){
    a *= d;
    c *= b;
    rutgon(a, c);
    cout<<a<<'/'<<c<<' ';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(FILENAME".INP", "r", stdin);
    //freopen(FILENAME".OUT", "w", stdout);
    cin>>a>>b>>c>>d;
    tong_hieu(a, b, c, d);
    tich(a, b, c, d);
    thuong(a, b, c, d);
    return 0;
}
