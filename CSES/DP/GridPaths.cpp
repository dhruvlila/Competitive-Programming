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
 
   vector <vll> obstacleGrid(n, vll(n));
   for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
         char c;
         cin >> c;
         if(c == '.'){
            obstacleGrid[i][j] = 0;
         }
         else{
            obstacleGrid[i][j] = 1;
         }
      }
   }
   ll m = n;
   vector <vector <ll>> dp(m+1, vector<ll>(n+1));
   for(ll i = 0; i <= n; i++){
      dp[0][i] = 0;
   }
   for(ll i = 0; i <= m; i++){
      dp[i][0] = 0;
   }
   if(obstacleGrid[0][0] == 1){
      dp[1][1] = 0;
   }
   else{
      dp[1][1] = 1;
   }
   for(ll i = 1; i <= m; i++){
      for(ll j = 1; j <= n; j++){
          if(!(i == 1 && j == 1)){
              if(obstacleGrid[i-1][j-1]){
                  dp[i][j] = 0;
              }
              else{
                  dp[i][j] = dp[i-1][j] + dp[i][j-1];
                  dp[i][j] %= MOD;
              }
          }
      }
   }
   cout << dp[n][n] << endl;
}
