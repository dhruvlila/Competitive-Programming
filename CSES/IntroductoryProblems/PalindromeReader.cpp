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

   string s;
   cin >> s;

   ll n = s.length();

   vll arr(26, 0);
   bool flag = true;
   bool ans = true;
   ll idx = -1;

   for(ll i = 0; i < n; i++){
      arr[int(s[i])-65]++;
   }
   for(ll i = 0; i < 26; i++){
      if(arr[i]&1){
         if(flag){
            flag = false;
            idx = i;
         }
         else{
            ans = false;
         }
      }
   }

   if(flag){
      string s = "";
      for(ll i = 0; i < 26; i++){
         for(ll j = 0; j < arr[i]/2; j++){
            s += char(i + 65);
         }
      }
      string t = s;
      reverse(t.begin(), t.end());
      s += t;
      cout << s;
   }
   else{
      if(!ans){
         cout << "NO SOLUTION" << endl;
      }
      else{
         string s = "";
         for(ll i = 0; i < 26; i++){
            if(!(arr[i] & 1)){
               for(ll j = 0; j < arr[i]/2; j++){
                  s += char(i + 65);
               }
            }  
         }
         string t = s;
         for(ll i = 0; i < arr[idx]; i++){
            s += char(idx + 65);
         }
         reverse(t.begin(), t.end());
         s += t;
         cout << s;
         }
   }

}
