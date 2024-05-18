// source : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 1e17;
const int MOD = 1e9+7;

void setIO(string name = "") {

	cin.tie(0)->sync_with_stdio(0); // see /general/fast-io

	if (sz(name)) {

		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output

		freopen((name + ".out").c_str(), "w", stdout);

	}

}

int main(){
  setIO("guard");

  int n;
  int h;
  cin >> n >> h;
  int hi[n];
  int wi[n];
  int st[n];
  for(int i = 0; i < n; i++){
    cin >> hi[i] >> wi[i] >> st[i];
  }

  pii dp[(1 << n)] = {};
  dp[0] = {0, INT32_MAX};

  for(int mask = 1; mask < (1 << n); mask++){
    dp[mask] = {0, -1};
    for(int i = 0; i < n; i++){
      if(mask & (1 << i)) dp[mask].first += hi[i];
      int prev = mask ^ (1 << i);
      dp[mask].second = max(min(dp[prev].second - wi[i], st[i]), dp[mask].second);
    }
  }

  int ans = -1;
  for(int mask = 1; mask < (1 << n); mask++){
    if(dp[mask].first >= h){
      ans = max(ans, dp[mask].second);
    }
  }
  if(ans < 0){
    cout << "Mark is too tall";
  }
  else{
    cout << ans;
  }
  return 0;
}