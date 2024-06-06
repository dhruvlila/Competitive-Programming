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

   vll arr(n);
   for(ll i = 0; i < n; i++){
      cin >> arr[i];
   }
   ll ans = 0;
   for(ll i = 0; i < n-1; i++){
      ans += max(0ll, arr[i]-arr[i+1]);
      arr[i+1] = max(arr[i], arr[i+1]);
   }
   cout << ans << endl;

}
