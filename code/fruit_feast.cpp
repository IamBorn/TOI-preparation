// source : https://usaco.org/index.php?page=viewproblem2&cpid=574

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

  freopen("feast.in", "r", stdin);
  freopen("feast.out", "w", stdout);
  int t, a, b;
  cin >> t >> a >> b;

  bool dp[t+5][2] = {};
  dp[0][0] = true;
  for(int i = 0; i <= t; i++){
    if(i - a >= 0){
      dp[i][0] |= dp[i-a][0];
    }
    if(i - b >= 0){
      dp[i][0] |= dp[i-b][0];
    }
    dp[i/2][1] |= dp[i][0];
  }

  for(int i = 0; i <= t; i++){
    if(i - a >= 0){
      dp[i][1] |= dp[i-a][1];
    }
    if(i - b >= 0){
      dp[i][1] |= dp[i-b][1];
    }
  }
  for(int i = t; i >= 0; i--){
    if(dp[i][1]){
      cout << i;
      break;
    }
  }
  return 0;
}