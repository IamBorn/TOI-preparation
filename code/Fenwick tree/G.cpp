// source : 
// status : incomplete
// date : 
// problem tags : 

#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size)
#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

struct Ftree{
  vector<ll> bit;
  int n;

  Ftree(int n){
    this->n = n;
    bit.assign(n, 0);
  }

  Ftree(vector<ll> const &a) : Ftree(a.size()) {
    for(int i = 0; i < a.size(); i++){
      add(i, a[i]);
    }
  }

  ll sum(int r){
    ll ret = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
      ret += bit[r];
    return ret;
  }

  void add(int idx, ll change){
    for(; idx < n; idx = idx | (idx + 1)){
      bit[idx] += change;
    }
  }
};

const int MX = 1e7+5;

void solve(){
  int n;
  cin >> n;

  Ftree t(MX);
  vi a(n);
  for(auto& it : a) cin >> it;

  ll ans = 0;
  for(int i = n-1; i >= 0; i--){
    ans += t.sum(a[i] - 1);
    t.add(a[i], 1);
  }

  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int t;
  cin >> t;
  while(t--){
    solve();
  }
  return 0;
}