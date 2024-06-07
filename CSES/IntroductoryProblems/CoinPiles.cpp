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

   ll x, y;
   cin >> x >> y;

   bool flag = true;
   if((x+y) % 3 != 0){
      flag = false;
   }
   if(x > 2*y || 2*x < y){
      flag = false;
   }

   (flag) ? cout << "YES\n" : cout << "NO\n";

}
