// source : 

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
  vector<ll> h(n);
  vector<ll> w(n);
  for(auto &it : h) cin >> it;
  for(auto &it : w) cin >> it;

  ll ans = 0;
  for(int i = 0; i < n ; i++){
    ll mn = INF;
    for(int j = i; j < n; j++){
      mn = min(mn, h[j]);
      ans += (mn * (mn+1) / 2) % MOD;
      ans %= MOD;
    }
  }
  cout << ans;
  return 0;
}