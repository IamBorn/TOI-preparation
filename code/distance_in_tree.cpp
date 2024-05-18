// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, k;
  cin >> n >> k;
  ll ans = 0;
  vector<vi> dp(n, vi(k+1));
  vector<vi> adj(n);
  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  function<void(int, int)> dfs = [&](int u, int p){
    dp[u][0] = 1;
    for(auto v : adj[u]){
      if(v == p) continue;

      dfs(v, u);
        for(int i = 0; i < k; i++){
        ans += dp[u][i] * dp[v][k - i - 1];
      }
      for(int i = 0; i < k; i++){
        dp[u][i+1] += dp[v][i];
      }
    }
  };

  dfs(0, -1);

  cout << ans;
  return 0;
}