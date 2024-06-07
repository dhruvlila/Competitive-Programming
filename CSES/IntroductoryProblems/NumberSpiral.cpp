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
   ll T;
   cin >> T;

   while(T--){
      solve();
   }

   return 0;

}

void solve(){

   ll m, n;
   cin >> m >> n;

   ll p = max(m , n);
   ll ans = 0;
   if((p & 1) == 1){
      if(m >= n){
         ans = (p-1);
         ans *= (p-1);
         ans += n;
      }
      else{
         ans = p;
         ans *= p;
         ans -= (m-1);
      }
   }
   else{
      if(m <= n){
         ans = (p-1);
         ans *= (p-1);
         ans += m;
      }
      else{
         ans = p;
         ans *= p;
         ans -= (n-1);
      }
   }

   cout << ans << endl;

}
