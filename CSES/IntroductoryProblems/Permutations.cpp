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

   if(n == 3 || n == 2){
      cout << "NO SOLUTION\n";
   }
   else{
      for(ll i = 2; i <= n; i += 2){
         cout << i << " ";
      }
      for(ll i = 1; i <= n; i += 2){
         cout << i << " ";
      }
   }

}
