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
   sort(s.begin(), s.end());
   vector <string> v;
   do{
      v.push(s);
   }while(next_permutation(s.begin(), s.end()));

   cout << v.size() << endl;
   for(auto &it : v){
      cout << it << endl;
   }


}
