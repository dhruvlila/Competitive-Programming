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
 
   ll n, x;
   cin >> n >> x;
 
   vll c(n);
   for(ll i = 0; i < n; i++){
      cin >> c[i];
   }
 
   vll dp(x+1, 0);
   dp[0] = 0;
 
   for(ll i = 1; i<=x; i++){
      ll m = INT_MAX;
      for(ll j = 0; j < n; j++){
         if(i - c[j] >= 0 && dp[i-c[j]] != -1){
            m = min(m, dp[i-c[j]]);
         }
      }
      if(m == INT_MAX){
         dp[i] = -1;
      }
      else{
         dp[i] = m + 1;
      }
   }
 
   if(dp[x] == 0){
      cout << -1 << endl;
   }
   else{
      cout << dp[x] << endl;
   }
 
}
