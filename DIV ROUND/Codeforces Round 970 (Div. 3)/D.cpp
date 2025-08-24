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

const int maxn = 2e5 + 3;
const int MOD = 1e9 + 7;
const int ooi = 1e9;
const long long ool = 1e18;
#define FILENAME ""

int t, n, p[maxn], used[maxn], f[maxn];
string s;

void sol(){
	memset(f, 0, sizeof f);
	memset(used, 0, sizeof used);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
    }
    cin >> s;
    
    for(int i = 0; i < n; i++){
        if(!used[i]){
            int pos = i;
            veci touris;
            while(!used[pos]){
                used[pos] = true;
                touris.push_back(pos);
                pos = p[pos];
            }
            
            int cnt = 0;
            for(int x : touris)
                if(s[x] == '0') cnt++;
            
            for(int x : touris){
                f[x] = cnt;
            }
        }
    }
    
    for(int i = 0; i < n; i++) cout << f[i] << ' ';
    cout << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(fopen(FILENAME".INP", "r")){
		freopen(FILENAME".INP", "r", stdin);
		freopen(FILENAME".OUT", "w", stdout);
	}
	cin >> t;
	while(t--) sol();
	return 0;
}