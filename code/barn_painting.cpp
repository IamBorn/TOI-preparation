// source : https://usaco.org/index.php?page=viewproblem2&cpid=766

#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io

	if (sz(name)) {

		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}

const int MxN = 100005;
vi adj[MxN];
int color[MxN];
ll dp[MxN][4];

void dfs(int u, int par){
  for(int v : adj[u]){
    if(v != par){
      dfs(v, u);
      dp[u][0] *= dp[v][1] + dp[v][2];
      dp[u][1] *= dp[v][0] + dp[v][2];
      dp[u][2] *= dp[v][1] + dp[v][0];
      dp[u][0] %= MOD;
      dp[u][1] %= MOD;
      dp[u][2] %= MOD;
    }
  }
}


int main(){
  setIO("barnpainting");
  
  int n, k;
  cin >> n >> k;
  memset(color, -1, sizeof(color));

  int u, v;
  for(int i = 0; i < n-1; i++){
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i = 1; i <= n; i++){
    dp[i][0] = 1;
    dp[i][1] = 1;
    dp[i][2] = 1;
  }
  int b, c;
  for(int i = 0; i < k; i++){
    cin >> b >> c;
    dp[b][0] = 0;
    dp[b][1] = 0;
    dp[b][2] = 0;
    dp[b][c-1] = 1;
  }

  dfs(1, 0);

  cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
  return 0;
}