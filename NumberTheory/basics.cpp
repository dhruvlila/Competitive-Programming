#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;

const ll MOD = 1e9 + 7;

class NumberTheory{
public:

   // Sieve of Eratosthenes to compute all primes from 1 --> n.
   // Time Complexity: O(n*log(log(n))), Space Complexity: O(n)
   vll soe(ll n){
      vector <bool> check(n+1, 1);
      for(ll i = 2; i*i <= n; i++){
         for(ll j = i*i; j <= n; j += i){
            check[j] = 0;
         }
      }
      vll ans;
      for(ll i = 2; i <= n; i++){
         if(check[i]) ans.push_back(i);
      }
      return ans;
   }

   // Prime Factorisation of a number with minimal space
   // Time Complexity: O(sqrt(n)), Space Complexity: O(map.size())
   map <ll, ll> primeSpace(ll n){
      map <ll, ll> map;
      if(!(n&1)){
         ll count = 0;
         while(!(n&1)){
            count++;
            n /= 2;
         }
         map[2] = count;
      }
      for(ll j = 3; j*j <= n; j += 2){
         if(n % j == 0){
            ll count = 0;
            while(n % j == 0){
               count++;
               n /= j;
            }
            map[j] = count;
         }
      }
      if(n > 1) map[n] = 1;
      return map;
   }

   // Prime Factorisation of a number with minimal time
   // Time Complexity: O(log(n)), Space Complexity: O(N)
   // Call helper function in main.
   ll N = 1e6;
   vll sieve(N+1, 0ll);
   void helper(){
      for(ll i = 2; i*i <= N; i++){
         if(sieve[i] == 0){
            sieve[i] = i;
            for(ll j = i*i; j <= N; j+= i){
               if(sieve[j] == 0){
                  sieve[j] = i;
               }
            }
         }
      }
   }
   map<ll, ll> primeTime(ll n){
      map <ll, ll> map;
      ll i = n;
      while(i != 1){
         map[sieve[i]]++;
         i /= sieve[i];
      }
      return map;
   }

   // Time Complexity: O(n^3)
   vector <vll> matrixMult(vector <vll> A, vector <vll> B){
      ll m = A.size();
      ll n = A[0].size();
      ll p = B[0].size();
      vector <vll> C(m, vll(p));
      for(ll i = 0; i < m; i++){
         for(ll j = 0; j < p; j++){
            ll sum = 0;
            for(ll k = 0; k < n; k++){
               sum += A[i][k]*B[k][j];
            }
            C[i][j] = sum;
         }
      }
      return C;
   }

   // Time Complexity: O(n^3*log(pow))
   vector <vll> matrixExpo(vector <vll> A, ll pow){
      ll n = A.size();
      vector <vll> I(n, vll(n, 0));
      for(ll i = 0; i < n; i++){
         for(ll j = 0; j < n; j++){
            if(i == j){
               I[i][j] = 1;
            }
         }
      }
      while(pow != 0){
         if(pow&1){
            I = matrixMult(I, A);
         }
         pow /= 2;
         A = matrixMult(A, A);
      }
      return I;
   }


};

int main(){

   ll N;
   cin >> N;

   return 0;

}
