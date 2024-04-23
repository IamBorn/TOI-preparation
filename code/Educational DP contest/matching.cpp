#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int MOD = 1e9+7;
const int sz = 22;
bool a[sz][sz];
int dp[1<<sz];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  dp[0] = 1;

  for(int mask = 0; mask < (1<<n); mask++){
    int bc = __builtin_popcount(mask);
    for(int i = 0; i < n; i++){
      if(a[bc][i] && !(mask>>i&1)){
        int out = mask^(1<<i);
        dp[out] += dp[mask];
        dp[out] %= MOD;
      }
    }
  }

  cout << dp[(1<<n)-1];
  return 0;
}