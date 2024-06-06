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
 
   ll n, x;
   cin >> n >> x;
 
   vll cost(n);
   vll pages(n);
   for(ll i = 0; i < n; i++){
      cin >> cost[i];
   } 
   for(ll i = 0; i < n; i++){
      cin >> pages[i];
   } 
 
   vll prev(x+1);
   for(ll i = 0; i <= x; i++){
      if(i >= cost[0]){
         prev[i] = pages[0];
      }
   }
 
   for(ll i = 1; i < n; i++){
      vll current(x+1);
      current[0] = 0;
      for(ll j = 1; j <= x; j++){
         ll skip = 0, keep = 0;
         skip = prev[j];
         if(j >= cost[i]){
            keep = prev[j-cost[i]] + pages[i];
         }
         current[j] = max(skip,keep);
      }
      prev = current;
   }
 
   cout << prev[x] << endl;
 
}
