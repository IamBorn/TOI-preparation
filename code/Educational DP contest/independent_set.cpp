#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MxN = 100005;
const int MOD = 1e9+7;

bool isV[MxN];

vector<int> adj[MxN];

ll dfs(int i, int color){
  ll ans = 1;
  isV[i] = true;
  for(auto j : adj[i]){
    if(isV[j]) continue;

    if(color == 0){
      ans *= (dfs(j, 1)) % MOD;
    }
    else{
      ans *= (dfs(j, 0) + dfs(j, 1)) % MOD;
    }
    ans %= MOD;
  }

  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x, y;
  for(int i = 0; i < n-1; i++){
    cin >> x >> y;
    adj[--x].push_back(--y);
    adj[y].push_back(x);
  }

  vector<array<int64_t, 2>> dp(n, {1, 1});
  auto dfs = [&](auto &&self, int cur, int par) -> void {
    for (int nbr : adj[cur]) {
      if (nbr != par) {
        self(self, nbr, cur);
        dp[cur][0] = dp[cur][0] * (dp[nbr][0] + dp[nbr][1]) % MOD;
        dp[cur][1] = dp[cur][1] * dp[nbr][0] % MOD;
      }
    }
  };
  dfs(dfs, 0, -1);
  cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
  return 0;
}