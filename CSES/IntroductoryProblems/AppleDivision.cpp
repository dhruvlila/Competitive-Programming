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
 
   ll n;
   cin >> n;
 
   vll arr(n);
   ll sum = 0;
   for(ll i = 0; i < n; i++){
      cin >> arr[i];
      sum += arr[i];
   }
 
   ll m = INT_MAX;
   for(ll i = 0; i < (1<<n); i++){
      ll p = 0;
      for(ll j = 0; j < n; j++){
         if((i>>j) & 1){
            p += arr[j];
         }
      }
      m = min(m, abs(sum-2*p));
   }
 
   cout << m << endl;
 
}
