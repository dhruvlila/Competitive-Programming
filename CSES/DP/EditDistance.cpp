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
 
   string s1, s2;
   cin >> s1 >> s2;
 
   ll m = s1.length();
   ll n = s2.length();
 
   vector <vll> dp(m+1, vll(n+1));
   for(ll i = 0; i <= n; i++){
      dp[0][i] = i;
   }
   for(ll i = 0; i <= m; i++){
      dp[i][0] = i;
   }
 
   for(ll i = 1; i <= m; i++){
      for(ll j = 1; j <= n; j++){
         if(s1[i-1] == s2[j-1]){
            dp[i][j] = dp[i-1][j-1];
         }
         else{
            dp[i][j] = dp[i-1][j-1] + 1;
            dp[i][j] = min(dp[i][j], min(dp[i-1][j] + 1, dp[i][j-1] + 1));
         }
      }
   }
 
   cout << dp[m][n] << endl;
 
 
 
 
}
