#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
 
#define push push_back
#define pop pop_back

void f(ll n, ll l, ll m, ll r){

   if(n == 1){
      cout << l << " " << r << endl;
   }
   else{
      f(n-1, l, r, m);
      cout << l << " " << r << endl;
      f(n-1, m, l, r);
   }

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
   cout << k - 1 << endl;

   f(n, 1, 2, 3);
}
