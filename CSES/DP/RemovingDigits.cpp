#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
 
#define push push_back
#define pop pop_back
 
const ll MOD = 1e9 + 7;
 
set <ll> f(ll n){
   set <ll> s;
   while(n != 0){
      if(n % 10 != 0){
         s.insert(n%10);
      }
      n /= 10;
   }
   return s;
}
 
void solve();
 
int main(){
 
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 
   solve();
 
   return 0;
 
}
 
void solve(){
 
   ll n;
   cin >> n;
 
   vll dp(n+1, 0);
   dp[0] = 0;
   for(ll i = 1; i <= n; i++){
      set <ll> s;
      s = f(i);
      ll m = INT_MAX;
      for(auto &it: s){
         m = min(m, dp[i-it]);
      }
      dp[i] = m+1;
   }
 
 
   cout << dp[n] << endl;
}
