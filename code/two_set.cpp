// source : https://cses.fi/problemset/task/1093

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
  
  int n;
  cin >> n;
  int sum = (n * (n+1) / 2);
  if(sum % 2 != 0){
    cout << "0";
    return 0;
  }
  sum /= 2;

  vector<ll> dp(sum + 1);
  vector<ll> prev(sum + 1);
  dp[0] = 1;
  for(int i = 1; i < n; i++){
    prev = dp;
    for(int j = 0; j <= sum; j++){
      dp[j] = prev[j];
      if(j >= i){
        dp[j] = (dp[j] + prev[j-i]) % MOD;
      }
    }
  }

  cout << dp[sum];
  return 0;
}