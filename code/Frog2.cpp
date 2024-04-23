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
  int n, k;
  cin >> n >> k;
  vi a(n);
  vi dp(n, INT_MAX);
  dp[0] = 0;
  for(auto& it : a) cin >> it;

  for(int i = 0; i < n-1; i++){
    for(int j = 1; j <= k && j + i < n; j++){
      dp[i+j] = min(dp[i+j], dp[i] + abs(a[i] - a[i+j]));
    }
  }

  cout << dp[n-1];
  return 0;
}