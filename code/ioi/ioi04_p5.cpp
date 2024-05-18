#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int q, m, k;
  cin >> q >> m >> k;
  vector<pair<ll, ll>> a; // first = value, second = weight
  ll in;
  for(int i = 0; i < m; i++){
    cin >> in;
    a.push_back({in, in});
  }
  for(int i = 0; i < k; i++){
    cin >> in;
    a.push_back({in-1, in});
  }

  vector<ll> dp(q+1, 0);
  vector<ll> prev;
  for(int i = 0; i < m+k; i++){
    prev = dp;
    for(int j = a[i].second; j <= q; j++){
      dp[j] = max(prev[j], prev[j - a[i].second] + a[i].first);
    }
  }
  cout << dp[q];
  return 0;
}