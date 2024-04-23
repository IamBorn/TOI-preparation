#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

void dfs(int v, vector<vi> &adj, vector<vi> &go, vector<vector<pii>> &k, int s, int t = -1, int p = -1, int len = 0){
  if(len == 1){
    t = v;
  }

  if(len > 1){
    go[s][v] = t;
  }

  k[len].push_back({s, v});

  for(auto u : adj[v]){
    if(u != p){
      dfs(u, adj, go, k, s, t, v, len+1);
    }
  }
}

void solve(){
  int n;
  string s;
  cin >> n >> s;
  vector<vi> adj(n);
  vector<vi> go(n, vi(n));
  vector<vector<pii>> k(n);
  vector<vi> dp(n, vi(n));
  int v, u;
  for(int i = 0; i < n-1; i++){
    cin >> v >> u;
    adj[--v].push_back(--u);
    adj[u].push_back(v);
  }

  for(int i = 0; i < n; i++){
    dfs(i, adj, go, k, i);
  }

  for(int len = 0; len < n; len++){
    for(auto [v, u] : k[len]){
      if(len == 0){
        dp[v][u] = 1;
      }
      else if(len == 1){
        dp[v][u] = 1 + (s[v] == s[u]);
      }
      else{
        int x = dp[v][go[u][v]];
        int y = dp[go[v][u]][u];
        dp[v][u] = max(max(x, y) , dp[go[v][u]][go[u][v]] + ((s[u] == s[v]) << 1));
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}