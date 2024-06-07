#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
 
#define push push_back
#define pop pop_back

void helper(ll n, ll x){
   vll bin(x, 0);
   ll i = 0;
   while(n != 0){
      if(n & 1){
         bin[i] = 1;
      }
      else{
         bin[i] = 0;
      }
      i++;
      n /= 2;
   }
   reverse(bin.begin(), bin.end());
   vll ans(x, 0);
   ans[0] = bin[0];
   for(ll i = 1; i < x; i++){
      ans[i] = bin[i] ^ bin[i-1];
   }
   for(ll i = 0; i < x; i++){
      cout << ans[i];
   }
   cout << endl;
}

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

   ll k = 1 << n;
   for(ll i = 0; i < k; i++){
      helper(i, n);
   }

}
