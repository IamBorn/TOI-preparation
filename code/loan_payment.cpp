// source : https://usaco.org/index.php?page=viewproblem2&cpid=991

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const long long INF = 2e9+7;
const int MOD = 1e9+7;

bool can(ll n, ll k, ll m, ll x){
  ll g = 0;
  while(k > 0 && g < n){
    ll y = (n - g) / x;
    if(y < m){
      ll lo = ((n - g) + (m - 1)) / m;
      return lo <= k;
    }

    ll mm = n - (x * y);
    ll nm = min((mm - g) / y + 1, k);
    g+= y * nm;
    k -= nm;
  }

  return g >= n;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("loan.in", "r", stdin);
  freopen("loan.out", "w", stdout);
  
  ll n, k, m;
  cin >> n >> k >> m;

  ll l = 1, r = n+1;
  while(l < r){
    ll mid = (l + r + 1) / 2;

    if(can(n, k, m, mid)){
      l = mid;
    }
    else{
      r = mid - 1;
    }
  }

  cout << l;
  return 0;
}