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
  vector<vector<int>> a(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> a[i][j];
    }
  }

  vector<int64_t> dp(1 << n), val(1 << n);

  auto gain = [&](int mask){
    vector<int> bits;
    for(int i = 0; i < 16; i++){
      if(mask >> i & 1) bits.push_back(i);
    }

    int64_t ret = 0;
    for(int i = 0; i < bits.size(); i++){
      for(int j = i + 1; j < bits.size(); j++){
        ret += a[bits[i]][bits[j]];
      }
    }
    return ret;
  };

  for(int i = 1; i < (1 << n); i++){
    dp[i] = val[i] = gain(i);
  }

  for(int i = 1; i < (1 << n); i++){
    for(int s = i; s; ){
      --s &= i;
      dp[i] = max(dp[i], dp[i ^ s] + val[s]);
    }
  }

  cout << dp.back();
  return 0;
}