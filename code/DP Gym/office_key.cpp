// source : https://codeforces.com/gym/302977/problem/E

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
  
  int n, k, p;
  cin >> n >> k >> p;
  vector<ll> a(n);
  vector<ll> b(k);
  for(auto &it : a) cin >> it;
  sort(all(a));
  for(auto &it : b) cin >> it;
  sort(all(b));

  vector<vector<ll>> dp(k+1, vector<ll>(n+1, INF));
  dp[0][0] = 0;

  for(int i = 0; i < k; i++){
    for(int j = 0; j <= n; j++){
      dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

      if(j < n){
        dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j] , abs(a[j] - b[i]) + abs(b[i] - p)));
      }
    }
  }
  cout << dp[k][n];
  return 0;
}