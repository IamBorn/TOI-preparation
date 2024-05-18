// source : https://atcoder.jp/contests/abc125/tasks/abc125_c

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
  vector<ll> a(n+1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  vector<ll> l(n+1);
  vector<ll> r(n+2);
  l[0] = 0;
  r[n+1] = 0;
  for(int i = 1; i <= n; i++){
    l[i] = __gcd(l[i-1], a[i]);
  }
  for(int i = n; i > 0; i--){
    r[i] = __gcd(r[i+1], a[i]);
  }
  ll ans = 0;
  for(int i = 1; i <= n; i++){
    ans = max(ans, __gcd(l[i-1], r[i+1]));
  }
  cout << ans;
  return 0;
}