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

   ll f = n*(n+1)/2;
   if(f & 1){
      cout << "NO\n";
   }

   else{
      cout << "YES\n";
      vll a;
      vll b;

      if(n & 1){
         a.push(1);
         a.push(2);
         b.push(3);
         for(ll i = 1; i <= (n-3)/2; i++){
            if(i&1){
               a.push(i+3);
               a.push(n-i+1);
            }
            else{
               b.push(i+3);
               b.push(n-i+1);
            }
         }
      }
      else{
         for(ll i = 1; i <= n/2; i++){
            if(i&1){
               a.push(i);
               a.push(n-i+1);
            }
            else{
               b.push(i);
               b.push(n-i+1);
            }
         }
      }
      cout << a.size() << endl;
      for(auto &it : a){
         cout << it << " ";
      }
      cout << endl << b.size() << endl;
      for(auto &it : b){
         cout << it << " ";
      }
   }

}
