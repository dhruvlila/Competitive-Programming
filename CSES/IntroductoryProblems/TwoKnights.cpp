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
   for(ll i = 1; i <= n; i++){
      ll t = (i*i)*(i*i-1)/2;
      ll p = max(0ll, 2*(i-1)*(i-2));
      p *= 2;
      cout << t - p << endl;
   }

}
