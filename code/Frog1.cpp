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
  vi a(n);
  vi dp(n, INT_MAX);
  dp[0] = 0;
  for(auto& it : a) cin >> it;

  for(int i = 0; i < n-1; i++){
    dp[i+1] = min(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
    if(i+2 <= n){
      dp[i+2] = min(dp[i+2], dp[i] + abs(a[i] - a[i+2]));
    }
  }

  cout << dp[n-1];
  return 0;
}