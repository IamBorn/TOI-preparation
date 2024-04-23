#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vi a(n), b(n), c(n);
  for(int i = 0; i < n; i++){
    cin >> a[i] >> b[i] >> c[i];
  }

  int dp[100005][3];
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];

  for(int i = 1; i < n; i++){
    dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i];
    dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i];
    dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + c[i];
  }

  cout << max(max(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
  return 0;
}