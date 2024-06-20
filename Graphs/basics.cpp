#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;

const ll MOD = 1e9 + 7;

class Graphs{
public:

   // Depth First Search
   void dfs(vector <vll> &graph, vector <bool> &visited, vector <ll> &ans, ll s){
   
      visited[s] = 1;
      ans.push_back(s);
      for(auto &it : graph[s]){
         if(!visited[it]){
            dfs(graph, visited, ans, it);
         }
      }
   }

   //Breadth First Search
   void bfs(vector <vll> &graph, vector <bool> &visited, vector <ll> &ans, ll s){
   
      queue <ll> q;
      q.push(s);
      visited[s] = 1;
   
      while(!q.empty()){
         ll node = q.front();
         q.pop();
         ans.push_back(node);
   
         for(auto &it : graph[node]){
            if(!visited[it]){
               q.push(it);
               visited[it] = 1;
            }
         }
      }
   }

   // Cycle Detection in a connected component
   bool cycleCheck(vector <vll> &graph, vector <bool> &visited, ll s){

      queue <pair<ll, ll>> q;
      q.push({s, -1});
      visited[s] = 1;

      while(!q.empty()){

         ll node = q.front().first;
         ll parent = q.front().second;
         q.pop();

         for(auto &it : graph[node]){
            if(!visited[it]){
               q.push({it, node});
               visited[it] = 1;
            }
            else if(it != parent){
               return true;
            }
         }
      }
      return false;
   }


};

int main(){

   ll V, E;
   vector <bool> visited(V+1, 0);
   vector <ll> ans; // Can be used to store bfs or dfs of a graph

   return 0;

}

