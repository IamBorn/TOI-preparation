// source : https://usaco.org/index.php?page=viewproblem2&cpid=945

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("snakes.in", "r", stdin);
  freopen("snakes.out", "w", stdout);
  
  int n, k;
  cin >> n >> k;
  vi a(n);
  for(int i = 1; i <= n; i++) cin >> a[i];

  int dp[405][405] = {};
  
  int mx = -1, used = 0;
  for(int i = 1; i <= n; i++){
    mx = max(mx, a[i]);

    dp[i][0] = mx * i;

    for(int j = 1; j <= k; j++){
      dp[i][j] = INF;
      int net = a[i];
      for(int l = i-1; l >= 0; l--){
        dp[i][j] = min(dp[i][j], dp[l][j-1] + net * (i - l));
        net = max(net, a[l]);
      }
    }
    used += a[i];
  }
  cout << dp[n][k] - used;
  return 0;
}