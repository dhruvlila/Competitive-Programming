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
 
   ll n, m;
   cin >> n >> m;
 
   vll arr(n);
   for(ll i = 0; i < n; i++){
      cin >> arr[i];
   }
 
   vector <vll> dp(n, vll(m+1));
   for(ll i = 0; i <= m; i++){
      dp[0][i] = 0;
      if(arr[0] == i || arr[0] == 0){
         dp[0][i] = 1;
      }
   }
   for(ll i = 0; i < n; i++){
      dp[i][0] = 0;
   }
 
   for(ll i = 1; i < n; i++){
      for(ll j = 1; j <= m; j++){
         dp[i][j] = 0;
         if((arr[i] == j) || arr[i] == 0){
            dp[i][j] = 1;
         }
         ll temp = dp[i-1][j] + dp[i-1][j-1];
         if(j < m){
            temp += dp[i-1][j+1];
            temp %= MOD;
         } 
         dp[i][j] *= temp;
         dp[i][j] %= MOD;
      }
   }
 
   ll sum = 0;
 
   for(ll i = 1; i <= m; i++){
      sum += dp[n-1][i];
      sum %= MOD;
   }
 
   cout << sum << endl;
 
}
