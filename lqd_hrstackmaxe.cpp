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

 stack<int> st;
 multiset<int> ms;
 int n;

 int main(){
     ios_base::sync_with_stdio(0); cin.tie(0);
     //freopen(FILENAME".INP", "r", stdin);
     //freopen(FILENAME".OUT", "w", stdout);
     cin>>n;
     while(n--){
        int k; cin>>k;
        if(k == 1){
            int x; cin>>x;
            st.push(x);
            ms.insert(x);
        }
        else if(k == 2){
            if(!ms.empty() && !st.empty()){
                ms.erase(ms.find(st.top()));
                st.pop();
            }
        }
        else{
            if(!ms.empty())cout<<*(ms.rbegin())<<'\n';
        }
     }
     return 0;
 }
