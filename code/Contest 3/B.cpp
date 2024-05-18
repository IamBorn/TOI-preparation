// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

vector<vi> adj;
int ans = 0;
int vis[100005];

void f(int u, int par){
  for(int v : adj[u]){
    if(v == par) continue;

    f(v, u);
    if(!vis[u] && !vis[v]){
      vis[u] = v;
      vis[v] = u;
      ans++;
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  adj.resize(n+1);
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  f(1, 0);
  cout << (n - ans) * 2 << "\n";
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      vis[i] = vis[adj[i][0]];
      vis[adj[i][0]] = i;
    }
  }

  for(int i = 1; i <= n; i++){
    cout << vis[i] << " ";
  }
  return 0;
}