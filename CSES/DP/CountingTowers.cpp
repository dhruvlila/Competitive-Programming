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
vll ans(1e6 + 1, 0);
vector <vll> dp(2, vll(1e6));
 
int main(){
 
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 
   ans[1] = 2;
   dp[0][1] = 1;
   dp[1][1] = 1;
   for(ll i = 2; i <= 1e6; i++){
      dp[0][i] = (4*dp[0][i-1] + dp[1][i-1]) % MOD;
      dp[1][i] = (2*dp[1][i-1] + dp[0][i-1]) % MOD;
      ans[i] = (dp[0][i] + dp[1][i]) % MOD;
   }
 
   ll T;
   cin >> T;
 
   while(T--){
      solve();
   }
 
   return 0;
 
}
 
void solve(){
 
   ll p;
   cin >> p;
 
   cout << ans[p] << endl;
 
}
