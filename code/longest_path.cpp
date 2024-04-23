#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

vi adj[100005];

int dp[100005];

int dfs(int i){
  if(dp[i] != -1){
    return dp[i];
  }
  int mx = 0;
  for(auto j : adj[i]){
    mx = max(mx, dfs(j));
  }

  return dp[i] = mx+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int x, y;
  memset(dp, -1, sizeof(dp));
  vi par(n, 0);
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    adj[--x].push_back(--y);
    par[y]++;
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(par[i] == 0){
      ans = max(ans, dfs(i));
    }
  }

  cout << ans-1;
  return 0;
}