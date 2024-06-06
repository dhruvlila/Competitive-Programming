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
 
   ll n;
   cin >> n;
 
   vector <vll> obstacleGrid(n, vll(n));
   for(ll i = 0; i < n; i++){
      for(ll j = 0; j < n; j++){
         char c;
         cin >> c;
         (c == '.') ? obstacleGrid[i][j] = 0 : obstacleGrid[i][j] = 1;
      }
   }

   vector <vector <ll>> dp(n+1, vector<ll>(n+1));
   for(ll i = 0; i <= n; i++){
      dp[0][i] = 0;
   }
   for(ll i = 0; i <= n; i++){
      dp[i][0] = 0;
   }
 
   (obstacleGrid[0][0] == 1) ? (dp[1][1] = 0) : (dp[1][1] = 1);
 
   for(ll i = 1; i <= n; i++){
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
