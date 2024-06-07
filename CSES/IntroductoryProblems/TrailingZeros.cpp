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
   
   ll t = 5;
   ll ans = 0;
   while(t <= n){
      ans += n/t;
      t *= 5;
   }

   cout << ans << endl;

}
