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

const int MOD = 1e9+7;

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
    for(; r >= 0; r = (r & (r + 1)) - 1){
      ret += bit[r];
      ret %= MOD;
    }
    return ret;
  }

  void add(int idx, ll change){
    change %= MOD;
    for(; idx < n; idx = idx | (idx + 1)){
      bit[idx] += change;
      bit[idx] %= MOD;
    }
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<ll> x(n);
  ll in;
  Ftree t(1e9+1);
  for(int i = 0; i < n; i++){
    cin >> in;
    t.add(in, t.sum(in-1)+1);
  }
  cout << t.sum(1e9) % MOD;
  return 0;
}