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

  ll sum(int l, int r){
    return sum(r) - sum(l-1);
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

  int qi;
  Ftree col(n);
  Ftree row(n);
  while(q--){
    cin >> qi;
    if(qi == 1){
      int x, y;
      
      cin >> x >> y;
      x--;
      y--;
      row.add(x, 1);
      row.add(x+1, -1);
      col.add(y, 1);
      col.add(y+1, -1);
    }
    else if(qi == 2){
      int x, y;
      
      cin >> x >> y;
      x--;
      y--;
      row.add(x, -1);
      row.add(x+1, 1);
      col.add(y, -1);
      col.add(y+1, 1);
    }
    else{
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--;
      x2--;
      y1--;
      y2--;
      if(row.sum(min(x1, x2)-1, max(x1, x2)) > 0 || col.sum(min(y1, y2)-1, max(y1, y2)) > 0){
        cout << "Yes\n";
      }
      else{
        cout << "No\n";
      }
    }
  }
  return 0;
}