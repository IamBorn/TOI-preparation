#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 1e9+7;

ll dp[105][100005] = {};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;

  vi a(n);
  for(auto& it : a) cin >> it;
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++){
    ll temp = 0;
    for(int j = 0; j <= k; j++){
      temp = (temp + dp[i-1][j]) % MOD;
      if(j - a[i-1] - 1 >= 0){
        temp = (temp - dp[i-1][j - a[i-1] - 1] + MOD) % MOD;
      }
      dp[i][j] = (dp[i][j] + temp) % MOD;
    }
  }
  cout << dp[n][k];
  return 0;
}