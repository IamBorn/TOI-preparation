#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

double dp[3005][3005];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<double> pi(n+1);
  for(int i = 1; i <= n; i++){
    cin >> pi[i];
  }

  dp[0][0] = 1;

  for(int i = 1; i <= n; i++){
    dp[i][0] = dp[i-1][0] * (1-pi[i]);
    for(int j = 1; j <= i; j++){
      dp[i][j] = (dp[i-1][j-1] * pi[i]) + (dp[i-1][j] * (1 - pi[i]));
    }
  }

  double ans = 0;
  for(int i = (n+1) / 2; i <= n; i++){
    ans += dp[n][i];
  }

  cout << fixed << setprecision(10) << ans;
  return 0;
}