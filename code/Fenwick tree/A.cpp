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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vector<ll> a(n);
  for(auto& it : a) cin >> it;

  Ftree t(n);
  int qi, l, r, k;
  ll u;
  while(q--){
    cin >> qi;
    if(qi == 1){
      cin >> l >> r >> u;
      l--;
      r--;
      t.add(l, u);
      t.add(r+1, 0-u);
    }
    else{
      cin >> k;
      k--;
      cout << a[k] + t.sum(k) << '\n';
    }
  }
  return 0;
}