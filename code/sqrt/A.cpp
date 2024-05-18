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

const int block_size = 400;

struct query{
  int l, r, idx;
  bool operator<(query other) const {
    return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vi a(n);
  for(auto& it : a) cin >> it;
  int t;
  cin >> t;
  vector<query> qi(t);
  for(int i = 0; i < t; i++){
    query temp;
    cin >> temp.l >> temp.r;
    temp.l--;
    temp.r--;
    temp.idx = i;
    qi[i] = temp;
  }

  vi ans(qi.size());
  sort(all(qi));
  map<int, int> ma;
  int ret = 0;

  int cur_l = 0;
  int cur_r = -1;

  for(auto q : qi){
    while(cur_l > q.l){
      cur_l--;
      ma[a[cur_l]]++;
      if(ma[a[cur_l]] == 1) ret++;
    }
    while(cur_r < q.r){
      cur_r++;
      ma[a[cur_r]]++;
      if(ma[a[cur_r]] == 1) ret++;
    }
    while(cur_l < q.l){
      ma[a[cur_l]]--;
      if(ma[a[cur_l]] == 0) ret--;
      cur_l++;
    }
    while(cur_r > q.r){
      ma[a[cur_r]]--;
      if(ma[a[cur_r]] == 0) ret--;
      cur_r--;
    }
    ans[q.idx] = ret;
  }

  for(auto it : ans) cout << it << '\n';
  return 0;
}