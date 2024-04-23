#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 1e9+7;

int dp[1005][1005] = {};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  string s[1005];
  for(int i = 0; i < n; i++){
    cin >> s[i];
  }
  
  dp[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i+1 < n && s[i+1][j] == '.'){
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
      }
      if(j+1 < m && s[i][j+1] == '.'){
        dp[i][j+1] += dp[i][j];
        dp[i][j+1] %= MOD;
      }
    }
  }

  cout << dp[n-1][m-1] % MOD;
  return 0;
}