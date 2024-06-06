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
   ll T = 1;
 
   while(T--){
      solve();
   }
 
   return 0;
 
}
 
void solve(){
 
   ll m, n;
   cin >> m >> n;
 
   vector <vll> dp(m+1, vll(n+1, 0));
   for(ll i = 0; i <= n; i++){
      dp[0][i] = 0;
   }
   for(ll i = 0; i <= m; i++){
      dp[i][0] = 0;
   }
 
   dp[1][1] = 0;
   for(ll i = 1; i <= m; i++){
      for(ll j = 1; j <= n; j++){
         if(i == j){
            dp[i][j] = 0;
         }
         else if(!(i == 1 && j == 1)){
            ll vertical = INT_MAX, horizontal = INT_MAX;
            for(ll k = 1; k < i; k++){
               horizontal = min(horizontal, dp[i-k][j] + dp[k][j] + 1);
            }
            for(ll k = 1; k < j; k++){
               vertical = min(vertical, dp[i][j-k] + dp[i][k] + 1);
            }
            dp[i][j] = min(vertical, horizontal);
         }
      }
   }
 
   cout << dp[m][n] << endl;
 
}
