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
 
   vll prev(x+1, 0);
   vll curr(x+1, 0);
   prev[0] = 1, curr[0] = 1;
 
   for(ll i = n-1; i > -1; i--){
      for(ll j = 1; j <= x; j++){
 
         ll skip = 0, use = 0;
         if(i < n-1){
            skip = prev[j];
            skip %= MOD;
         } 
         if(j >= c[i]){
            use = curr[j-c[i]];
            use %= MOD;
         }
         curr[j] = skip + use;
         curr[j] %= MOD;
      }
      prev = curr;
      vll temp(x+1, 0);
      curr = temp;
      curr[0] = 1;
   }
 
   cout << prev[x] << endl;
}
