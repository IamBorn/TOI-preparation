// source : https://usaco.org/index.php?page=viewproblem2&cpid=863

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
  freopen("teamwork.in", "r", stdin);
  freopen("teamwork.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  vi a(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vi dp(n);

  for(int i = 1; i <= n; i++){
    int mx = 0;
    for(int j = 1; j <= k && j <= i; j++){
      mx = max(mx, a[i-j+1]);
      dp[i] = max(dp[i], dp[i-j] + (mx * j));
    }
  }

  cout << dp[n];
  return 0;
}