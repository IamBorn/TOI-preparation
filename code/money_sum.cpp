// source : https://cses.fi/problemset/task/1745

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
  vi a(n);
  ll sum = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    sum += a[i];
  }

  vector<bool> dp(sum + 1);
  vector<bool> prev(sum + 1);
  dp[0] = true;
  for(int i = 0; i < n; i++){
    prev = dp;
    for(int j = 0; j <= sum; j++){
      dp[j] = prev[j];
      if(j >= a[i]){
        dp[j] = prev[j - a[i]] || dp[j];
      }
    }
  }

  vi ans;
  for(int i = 1; i <= sum; i++){
    if(dp[i]) ans.push_back(i);
  }

  cout << ans.size() << "\n";
  for(auto i : ans) cout << i << " ";
  return 0;
}